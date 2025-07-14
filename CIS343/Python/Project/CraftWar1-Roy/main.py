"""Main module for the game.

This module is the main entry point for the game. It sets up the game window,
loads the game resources, and starts the game loop.

INSTRUCTIONS:
    You as the player are in control of the human forces. You must defeat the group
    of monsters to win the game. You can select and deselect your units by clicking 
    on them. You can then move selected units by clicking on the game field. You can
    also attack enemy units by clicking on them, or by moving your selected units
    close enough to them. Your units will automatically attack the enemy units when
    they are in range, but sometimes they need to be told to attack (freeloaders am i right?).

Author:
    Richard Roy

Date:
    2023-12-10
    
Resources:
    Background tileset: https://opengameart.org/content/cave-tileset-2
    Font: https://www.dafont.com/bitmap.php
"""

import os
import pygame as pg
from pygame.locals import * # pylint: disable=wildcard-import, unused-wildcard-import
from melee import Melee
from ranged import Ranged
from projectile import Projectile

def on_entity_click(entities, entity):
    """This function is called when an entity is clicked.
    
    It will select the entity if it is a player unit and not already selected.
    If the entity is already selected, it will deselect it.
    If the entity is an enemy, any selected player units will attack it.
    Projectile units will not be selected.

    Args:
        entities (list): A list of all entities in the game.
        entity (Entity): The entity that was clicked.
        delta (float): The time since the last frame.
    """
    if entity.team == 'player' and entity.unit_type != 'projectile':
        if entity.selected is False:
            entity.selected = True
        else:
            entity.selected = False
    elif entity.team == 'enemy':
        for entity_it in entities:
            if entity_it.team == 'player':
                if entity_it.selected is True:
                    entity_it.attack(entity)

def on_game_field_click(entities, x, y):
    """This function is called when the game field is clicked.
    
    It will move all selected player units to the clicked location.
    By updating their destination coordinates.

    Args:
        entities (List): List of all entities in the game.
        x (int): x coordinate of the click.
        y (int): y coordinate of the click.
    """
    for entity in entities:
        if entity.team == 'player':
            if entity.selected is True:
                entity.move_to(x, y)

def main(): # pylint: disable=too-many-locals, too-many-statements, too-many-branches
    """Main method for the game.
    
    Attributes:
        screen (Surface): The game window.
        background (Surface): The background image.
        entities (List): List of all entities in the game.
        running (bool): Is the game running?
        delta (float): Time since the last frame.
        shot_delta (float): Time since the last shot.
        animation_delta (float): Time since the last animation update.
        attack_speed_delta (float): Time since the last attack.
        fps (int): Frames per second.
        clock (Clock): Clock to keep consistent fps/updates.
        score (int): The player's score. Increases when an enemy is killed.
        gameover (bool): Is the game over? Used to break the game loop 
            and display the game over screen.
    """
    # Startup pygame
    pg.init()   # pylint: disable=no-member

    # Get a screen object
    screen = pg.display.set_mode([825, 825]) # class dimensions

    # Background
    background = pg.image.load('./assets/tile_sheet_960px_by_960px.png')

    entities = pg.sprite.Group()

    # player
    melee = Melee((275, 200), 'player')
    entities.add(melee)
    melee = Melee((250, 150), 'player')
    entities.add(melee)
    melee = Melee((200, 125), 'player')
    entities.add(melee)
    melee = Melee((200, 200), 'player')
    entities.add(melee)
    melee = Melee((200, 275), 'player')
    entities.add(melee)
    melee = Melee((250, 250), 'player')
    entities.add(melee)
    ranged = Ranged((150, 250), 'player')
    entities.add(ranged)
    ranged = Ranged((150, 175), 'player')
    entities.add(ranged)
    # enemy
    melee = Melee((625, 550), 'enemy')
    entities.add(melee)
    melee = Melee((700, 525), 'enemy')
    entities.add(melee)
    melee = Melee((700, 600), 'enemy')
    entities.add(melee)
    melee = Melee((700, 675), 'enemy')
    entities.add(melee)
    melee = Melee((625, 650), 'enemy')
    entities.add(melee)
    ranged = Ranged((750, 650), 'enemy')
    entities.add(ranged)
    ranged = Ranged((750, 575), 'enemy')
    entities.add(ranged)

    # Start sound
    
    # I do not have the license to use my music (Warcraft 1 Human theme)
    # Realizing this too late to find a replacement
    # So i will not be using music in my game
    pg.mixer.music.load("./assets/04 - Human 1.mp3")
    pg.mixer.music.play(-1)

    # Get font setup
    pg.freetype.init()
    font_path = os.path.join(
        os.path.dirname(os.path.realpath(__file__)), "./assets/", "Retro Gaming.ttf")
    font_size = 64
    font = pg.freetype.Font(font_path, font_size)
    white = (254, 254, 254)

    # Startup the main game loop
    running = True
    delta = 0
    shot_delta = 500
    animation_delta = 500
    attack_speed_delta = 500
    fps = 60
    clock = pg.time.Clock()
    clock.tick(fps)
    score = 0
    gameover = False
    while running:
        # First thing we need to clear the events
        for event in pg.event.get():
            # Quit game event
            if event.type == pg.QUIT:   # pylint: disable=no-member
                running = False
            # Mouse click event
            if event.type == pg.MOUSEBUTTONUP:  # pylint: disable=no-member
                pos = pg.mouse.get_pos()
                entity_clicked = False
                for entity in entities:
                    if entity.rect.collidepoint(pos):
                        on_entity_click(entities, entity)
                        entity_clicked = True
                if entity_clicked is False:
                    on_game_field_click(entities, pos[0], pos[1])

        # Score check
        if score >= 700:
            print("You win!")
            gameover = True
            
        no_units = True  # if the player has no units left, they lose
        for entity in entities:
            # projectile units are not counted
            if entity.team == 'player' and entity.unit_type != 'projectile':
                if entity.dead is False:
                    no_units = False
        if no_units is True:
            print("You lose!")
            gameover = True

        # Ok, events are handled, let's draw!
        # background instantiation
        screen.blit(background, (0, 0))

        if gameover is True:
            break

        # update entities
        for entity in entities:
            entity.update(entities,  delta)

         # update combat every .50 seconds
        if attack_speed_delta >= .50:
            for entity in entities:
                # Continuous combat functionality
                # If an entity is in combat, it will try to attack its target
                if entity.in_combat_with is not None and entity.unit_type != 'projectile':
                    # If the entity is a ranged unit, spawn a projectile
                    # at the entity's location and send it towards the target
                    if entity.unit_type == 'ranged':
                        projectile = Projectile(entity.rect.center, entity.in_combat_with)
                        entities.add(projectile)
                        break
                    entity.attack(entity.in_combat_with)
            # Reset combat timer
            attack_speed_delta = 0

        # update entities animation every .10 seconds
        if animation_delta >= .10:
            for entity in entities:
                # Since score is updated in the entity's update_animation method
                # when updating the animation, we need to add the score to the
                # global score variable
                score += entity.update_animation()
            # Reset animation timer
            animation_delta = 0

        entities.draw(screen)

        # Draw score
        font.render_to(screen, (10, 10), "Score: " + str(score), white, None, size=64)

        # When drawing is done, flip the buffer.
        pg.display.flip()

        # Update all the timers
        delta = clock.tick(fps) / 1000.0
        shot_delta += delta
        animation_delta += delta
        attack_speed_delta += delta

    # game is over
    while running:
        # Quit end screen event
        for event in pg.event.get():
            if event.type == pg.QUIT:   # pylint: disable=no-member
                running = False

        screen.blit(background, (0, 0))

        entities.draw(screen)

        font.render_to(screen, (10, 10), "Score: " + str(score), white, None, size=64)

        # Draw game over message (win or lose)
        if score >= 700:
            font.render_to(screen, (250, 350), "You win!", white, None, size=64)
        else:
            font.render_to(screen, (250, 350), "You lose!", white, None, size=64)

        pg.display.flip()

# Startup the main method to get things going.
if __name__ == "__main__":
    main()
    pg.quit()
