#pragma once
#include "Particle.h"
#include "Wall.h"
#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <SFML/Graphics.hpp>

extern const int HEIGHT; 
extern const int WIDTH;
extern sf::Clock frame_clock; 

/*
    This function handles the bouncing of particles on the screen
    edges and walls.
*/
void handle_collision(Particle& particle, const sf::Vector2u& window_size, bool is_collide, float delta);

/*
    This function determines whether a particle will intersect
    with a wall given its current position and projected position.
    If the particle will intersect with a wall, it will return a
    the position that is closest to the wall, otherwise, it will
    return the original projected position.
*/
sf::Vector2f get_offset(Particle particle, Wall wall, float delta);


void update_particle_batch(std::vector<Particle>& particles, size_t start, size_t end);


std::vector<std::thread> update_particles(std::vector<Particle>& particles);
