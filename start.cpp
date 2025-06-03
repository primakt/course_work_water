#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <conio.h>  // for _kbhit() and _getch()

using namespace std;

const int WIDTH = 80;
const int HEIGHT = 24;
const int NUM_PARTICLES = 10;
const float GRAVITY = 0.1f;
const int FPS = 15;

struct Vec2 {
    float x, y;
    Vec2 operator+(const Vec2& v) const { return { x + v.x, y + v.y }; }
    Vec2 operator-(const Vec2& v) const { return { x - v.x, y - v.y }; }
    Vec2 operator*(float f) const { return { x * f, y * f }; }
    float length() const { return sqrt(x * x + y * y); }
    Vec2 normalized() const {
        float len = length();
        return len == 0 ? Vec2{ 0,0 } : Vec2{ x / len, y / len };
    }
};

struct Particle {
    Vec2 pos;
    Vec2 vel;
};

void clearScreen() {
    // Windows console clear screen
    system("cls");
}

void renderPattern1(const vector<Particle>& particles) {
    char buffer[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            buffer[y][x] = ' ';

    for (auto& p : particles) {
        int px = int(p.pos.x);
        int py = int(p.pos.y);
        if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
            buffer[py][px] = '*';
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            cout << buffer[y][x];
        }
        cout << '\n';
    }
}

void renderPattern2(const vector<Particle>& particles) {
    // Render a "density" based projection
    int density[HEIGHT][WIDTH] = { 0 };

    for (auto& p : particles) {
        int px = int(p.pos.x);
        int py = int(p.pos.y);
        if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
            density[py][px]++;
            // Spread a little around
            if (px + 1 < WIDTH) density[py][px + 1]++;
            if (px - 1 >= 0) density[py][px - 1]++;
            if (py + 1 < HEIGHT) density[py + 1][px]++;
            if (py - 1 >= 0) density[py - 1][px]++;
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int d = density[y][x];
            if (d == 0) cout << ' ';
            else if (d < 2) cout << '.';
            else if (d < 4) cout << 'o';
            else cout << 'O';
        }
        cout << '\n';
    }
}

int main() {
    vector<Particle> particles(NUM_PARTICLES);

    // Initialize particles randomly in the top half
    srand((unsigned)time(NULL));
    for (auto& p : particles) {
        p.pos = { float(rand() % WIDTH), float(rand() % (HEIGHT / 2)) };
        p.vel = { 0, 0 };
    }

    int pattern = 1;

    while (true) {
        // Clear screen
        clearScreen();

        // Update physics
        for (int i = 0; i < NUM_PARTICLES; i++) {
            Particle& p = particles[i];

            // Apply gravity
            p.vel.y += GRAVITY;

            // Simple collision with floor
            if (p.pos.y + p.vel.y >= HEIGHT - 1) {
                p.vel.y = -p.vel.y * 0.6f; // bounce with damping
                p.pos.y = HEIGHT - 1;
            }

            // Simple collision with walls
            if (p.pos.x + p.vel.x >= WIDTH - 1 || p.pos.x + p.vel.x < 0) {
                p.vel.x = -p.vel.x * 0.8f;
            }

            // Update position
            p.pos = p.pos + p.vel;

            // Keep inside bounds
            if (p.pos.x < 0) p.pos.x = 0;
            if (p.pos.x >= WIDTH) p.pos.x = WIDTH - 1;
            if (p.pos.y < 0) p.pos.y = 0;
            if (p.pos.y >= HEIGHT) p.pos.y = HEIGHT - 1;
        }

        // Basic interaction (object decomposition): repel particles slightly if too close
        for (int i = 0; i < NUM_PARTICLES; i++) {
            for (int j = i + 1; j < NUM_PARTICLES; j++) {
                Vec2 diff = particles[j].pos - particles[i].pos;
                float dist = diff.length();
                if (dist > 0 && dist < 2.0f) {
                    Vec2 repel = diff.normalized() * 0.05f;
                    particles[j].vel = particles[j].vel + repel;
                    particles[i].vel = particles[i].vel - repel;
                }
            }
        }

        // Render according to pattern
        if (pattern == 1) renderPattern1(particles);
        else renderPattern2(particles);

        cout << "\nPress 'p' to toggle pattern, 'q' to quit.\n";

        // Handle input non-blocking
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'p' || ch == 'P') {
                pattern = 3 - pattern; // switch 1 <-> 2
            }
            else if (ch == 'q' || ch == 'Q') {
                break;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(1000 / FPS));
    }

    return 0;
}
