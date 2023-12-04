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

        # Player or enemy
        self.team = team
        # Health
        self.hp = 100
        # Melee or ranged or gather
        self.attackType = 'melee'
        # Damage per attack
        self.damage = 10
        # Movement speed in pixels per second
        self.moveSpeed = 100
    
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