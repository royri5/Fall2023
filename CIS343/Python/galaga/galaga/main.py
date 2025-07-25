#!/usr/bin/env python3

import pygame as pg
import os
from enemy import Enemy
from player import Player
from projectile import Projectile
from pygame.locals import *

def main():
    # Startup pygame
    pg.init()

    # Get a screen object
    screen = pg.display.set_mode([1024, 768])
    
    # Create game objects
    player = Player()
    enemies = pg.sprite.Group()
    projectiles = pg.sprite.Group()

    # Spawn enemies?
    # Start at x = 500, y = 100
    # Place enemies every +75 x and +50 y
    # Until x = 1000 and y = 600
    for i in range(500, 1000, 75):
        for j in range(100, 600, 50):
            enemy = Enemy((i, j))
            enemies.add(enemy)

    # Start sound
    pg.mixer.music.load('./assets/cpu-talk.mp3')
    pg.mixer.music.play(-1)

    # Get font setup
    pg.freetype.init()
    font_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "./assets/", "PermanentMarker-Regular.ttf")
    font_size = 64
    font = pg.freetype.Font(font_path, font_size)
    WHITE = (254, 254, 254)
    
    # Startup the main game loop
    running = True               
    delta = 0                   # Time between frames used for updating 
    shotDelta = 500             # Time between frames used for shooting
    fps = 60                    # Frames per second
    clock = pg.time.Clock()     # Clock for using delta
    clock.tick(fps)             # How often to update the clock
    score = 0                   # Used for wincon
    while running:
        # First thing we need to clear the events.
        for event in pg.event.get():
            if event.type == pg.QUIT:
                running = False
            if event.type == pg.USEREVENT + 1:
                score += 100
        keys = pg.key.get_pressed()
        if keys[K_s]:
            player.down(delta)
        if keys[K_w]:
            player.up(delta)
        if keys[K_SPACE]:
            if shotDelta >= .25:
                projectile = Projectile(player.rect, enemies)
                projectiles.add(projectile)
                shotDelta = 0
        if len(enemies) == 0:
            print("You've cleared the galaxy of evil!")
            return

        # Ok, events are handled, let's draw!
        screen.fill((0, 0, 0))

        player.update(delta)
        
        for enemy in enemies:
            enemy.update(delta)
        for projectile in projectiles:
            projectile.update(delta)

        player.draw(screen)
        enemies.draw(screen)
        projectiles.draw(screen)
        # Text on screen
        font.render_to(screen, (10, 10), "Score: " + str(score), WHITE, None, size=64)

        # When drawing is done, flip the buffer.
        pg.display.flip()

        # Update the delta and shotDelta
        delta = clock.tick(fps) / 1000.0
        shotDelta += delta

# Startup the main method to get things going.
if __name__ == "__main__":
    main()
    pg.quit()
