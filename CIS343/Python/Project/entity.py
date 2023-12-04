import os
import pygame as pg

class Entity(pg.sprite.Sprite):
    def __init__(self, startLocation, team, imagePath):
        super(Entity, self).__init__()
        # Image handling
        self.image = pg.image.load(os.path.join('assets', imagePath)).convert_alpha()
        # Hitbox handling
        self.rect = self.image.get_rect()
        self.rect.centerx = startLocation[0]
        self.rect.centery = startLocation[1]
        self.startLocation = startLocation
        self.direction = 1

        self.team = team                # Player or enemy
        self.hp = 100                   # Health
        self.attackType = 'melee'       # Melee or ranged or gather
        self.damage = 10                # Damage per attack
        self.moveSpeed = 100            # Movement speed in pixels per second
    
    def draw(self, screen):
        screen.blit(self.image, self.rect)
    
    # "AI" actions
    def update(self, delta):
        # TODO:
        #   - Movement
        #   - Attack
        #   - Gather
        pass

    # Player controlled actions
    # TODO:
    #   - Movement
    #   - Attack
    #   - Gather

    # move to mouse loc