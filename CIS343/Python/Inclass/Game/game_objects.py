import pygame as pg

#class code

class Player(pg.sprite.Sprite):
    def __init__(self):
        super(Player, self).__init__()
        self.image = pg.image.load('./goblin8bit.png').convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.centerx = 320
        self.rect.centery = 240


    def up(self):
        if self.rect.y > 0:
            self.rect.y -= 50

    def down(self):
        if self.rect.y < 480:
            self.rect.y += 50

    def left(self):
        if self.rect.x > 0:
            self.rect.x -= 50

    def right(self):
        if self.rect.x < 640:
            self.rect.x += 50
    
