"""This module contains the Projectile class.

The Projectile class is a subclass of the Entity class. It is used to create
projectiles that are spawned by ranged units when they attack. The projectile
moves towards the target unit and if it collides with the target, it deals
damage to the target and despawns.

Author:
    Richard Roy

Date:
    2023-12-10

Resources:
    https://opengameart.org/content/retropixel-icons-v1-9x9
"""

import math
import pygame as pg
from entity import Entity

class Projectile(Entity):   # pylint: disable=too-many-instance-attributes
    """Class for creating projectiles.

    Inherits from the Entity class.
    
    Attributes:
        target (Entity): The target the ranged unit is attacking.
    """
    def __init__(self, start_location, target):
        """Constructor for the Projectile class.

        Args:
            start_location (tuple): The location where the projectile is spawned.
            target (Entity): The target the ranged unit is attacking.
        """
        super().__init__(start_location, 'player')
        self.idle_frame_set = []
        self.walk_frame_set = []
        self.action_frame_set = []
        self.death_frame_set = []
        self.frame_number = 0
        self.unit_type = 'projectile'
        self.speed = 300
        self.target = target

        self.width = 9
        self.height = 9

        # Loading animation frame sets
        start_frame = 0
        end_frame = 1
        row = 0
        self.add_idle_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        self.add_idle_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        row = 0
        self.add_idle_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        self.add_idle_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        row = 0
        self.add_walk_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        self.add_idle_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        row = 0
        self.add_action_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        self.add_idle_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        row = 0
        self.add_death_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)
        self.add_idle_frame_set(
            './assets/circle_white.png', start_frame, end_frame, row, self.width, self.height)

        start_frame = self.idle_frame_set[self.frame_number]
        self.update_frame(start_frame)
        self.move_to(target.location[0], target.location[1])

    @property
    def target(self):
        return self.__target
    @target.setter
    def target(self, target):
        self.__target = target

    # ranged attacks
    # spawn projectile at attacker's location
    # projectile moves towards target
    # collides only with target
    # despawns on collision or after a set time(dies early)
    def update(self, entities, delta):  # pylint: disable=too-many-branches
        """Update the projectile's location and check for collisions.
        
        Overrides the update method in the Entity class. In order to alter the
        collision detection and movement of the projectile and to
        allow the projectile to inherit from the Entity class.
        
        Assisted by ChatGPT.

        Args:
            entities (List): List of all entities in the game.
            delta (float): Time since last frame.
        """
        # State updates
        if self.doing == 'death':
            return
        if self.hp <= 0:
            self.death()
            return
        if self.doing == 'action':
            if self.in_combat_with is None or self.in_combat_with.doing == 'death':
                self.idle()
                return

        # Movement towards target
        if self.destination != self.location:
            if self.doing != 'walk':
                self.walk_aggro()
            x_diff = self.destination[0] - self.location[0]
            y_diff = self.destination[1] - self.location[1]
            distance = math.sqrt(x_diff**2 + y_diff**2)
            if distance > 10:
                direction_x = x_diff / distance
                direction_y = y_diff / distance
                # Direction faced is based on direction of movement
                if direction_x > 0:
                    self.direction = 1
                else:
                    self.direction = -1
                self.rect.centerx += direction_x * self.speed * delta
                # Collision detection
                for entity in entities:
                    if entity != self and entity == self.target:
                        if pg.sprite.collide_rect(self, entity):
                            entity.hp -= self.attack_damage
                            self.death()
                self.rect.centery += direction_y * self.speed * delta
                self.location = (self.rect.centerx, self.rect.centery)
                return
            # Target destroyed before projectile reaches it
            self.kill()
            self.location = (self.rect.centerx, self.rect.centery)
        # Projectile despawns if it reaches its destination
        # and the target is not there
        else:
            self.kill()
        self.location = (self.rect.centerx, self.rect.centery)
