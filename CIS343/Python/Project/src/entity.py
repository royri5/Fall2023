
"""This module contains the Entity class.

This class houses the functionality for all entities in the game.
Never to be instantiated directly, but to be inherited by 
Melee, Ranged, and Projectile classes.

Author:
    Richard Roy

Date:
    2023-12-10

Resources:
    Default entity: https://opengameart.org/content/animated-warrior

References:
    https://www.geeksforgeeks.org/mmouse-clicks-on-sprites-in-pygame/
"""

import math
import pygame as pg
from spritesheet import Spritesheet

class Entity(pg.sprite.Sprite): # pylint: disable=too-many-instance-attributes, too-many-public-methods
    """Class for handling the functionality of all entities in the game.
    
    Inherits from pygame.sprite.Sprite.

    Attributes:
        hp (int): The health points of the entity.
        speed (int): The movement speed of the entity.
        attack_damage (int): The damage dealt by the entity per hit.
        attack_range (int): The range of the entity's attack.
        unit_type (str): The type of unit the entity is. 
            (melee, ranged, projectile)
        team (str): The team the entity is on.  
            (player, enemy)
        selected (bool): Whether the entity is selected or not. 
            (player unit control)
        doing (str): The current action the entity is doing.    
            (idle, walk, action, death)
        in_combat_with (Entity): The unit(entity) the entity is in combat with.
        dead (bool): Whether the entity is dead or not. 
            (enabled post-death animation for removal)
        location (tuple): The current location of the entity.   
            (x, y)
        destination (tuple): The destination the entity is moving towards. 
            (x, y)
        direction (int): The direction the entity is facing. Used for sprites.
            (1 for right, -1 for left)
        idle_frame_set (list): The list of idle frames for the entity.
        walk_frame_set (list): The list of walk frames for the entity.
        action_frame_set (list): The list of combat frames for the entity.
        death_frame_set (list): The list of death frames for the entity.
        frame_number (int): The current frame of animation.
        width (int): The width of each sprite on the spritesheet.
        height (int): The height of each sprite on the spritesheet.
    """
    def __init__(self, start_location, team):
        """Constructor for the Entity class.

        Args:
            start_location (tuple): The starting location of the entity. (x, y)
            team (str): The team the entity is on. (player, enemy)
        """
        super(Entity, self).__init__()  # pylint: disable=super-with-arguments

        # Initialize sprites to empty list
        self.__idle_frame_set = []
        self.__walk_frame_set = []
        self.__action_frame_set = []
        self.__death_frame_set = []

        # default spritesheet and animation frame variables
        self.frame_number = 0        # current frame of animation
        self.width = 32         # width of each sprite on spritesheet
        self.height = 32        # height of each sprite on spritesheet

        # group of frames in row to be loaded
        start_frame = 0
        end_frame = 9          
        row = 0                 # row of spritesheet to look in
        self.add_idle_frame_set(
            './assets/warrior spritesheet calciumtrice.png',
            start_frame, end_frame, row, self.width, self.height)
        row = 1
        self.add_idle_frame_set(
            './assets/warrior spritesheet calciumtrice.png',
            start_frame, end_frame, row, self.width, self.height)
        row = 2
        self.add_walk_frame_set(
            './assets/warrior spritesheet calciumtrice.png',
            start_frame, end_frame, row, self.width, self.height)
        row = 3
        self.add_action_frame_set(
            './assets/warrior spritesheet calciumtrice.png',
            start_frame, end_frame, row, self.width, self.height)
        row = 4
        self.add_death_frame_set(
            './assets/warrior spritesheet calciumtrice.png',
            start_frame, end_frame, row, self.width, self.height)

        # default unit stats
        self.hp = 100
        self.speed = 100
        self.attack_damage = 10
        self.attack_range = 46
        self.unit_type = 'melee'

        # default unit state variables
        self.team = team
        self.selected = False
        self.doing = 'idle'        # idle, walk, action, death
        self.in_combat_with = None
        self.dead = False
        self.location = start_location
        self.destination = start_location
        self.direction = 1          # 1 = Right, -1 = Left

        # default sprite and image creation
        start_frame = self.idle_frame_set[self.frame_number]
        self.update_frame(start_frame)

    # Properties
    # unit stat variables
    @property
    def hp(self):
        return self.__hp
    @hp.setter
    def hp(self, hp):
        if hp is None:
            raise ValueError("hp cannot be blank")
        if not isinstance(hp, int):
            raise ValueError("hp must be an integer")
        if hp <= 0:
            self.doing = 'death'
        self.__hp = hp
    @property
    def speed(self):
        return self.__speed
    @speed.setter
    def speed(self, speed):
        if speed is None:
            raise ValueError("speed cannot be blank")
        if not isinstance(speed, int):
            raise ValueError("speed must be an integer")
        if speed < 0:
            raise ValueError("speed cannot be negative")
        self.__speed = speed
    @property
    def attack_damage(self):
        return self.__attack_damage
    @attack_damage.setter
    def attack_damage(self, attack_damage):
        if attack_damage is None:
            raise ValueError("attack_damage cannot be blank")
        if not isinstance(attack_damage, int):
            raise ValueError("attack_damage must be an integer")
        if attack_damage < 0:
            raise ValueError("attack_damage cannot be negative")
        self.__attack_damage = attack_damage
    @property
    def attack_range(self):
        return self.__attack_range
    @attack_range.setter
    def attack_range(self, attack_range):
        if attack_range is None:
            raise ValueError("attack_range cannot be blank")
        if not isinstance(attack_range, int):
            raise ValueError("attack_range must be an integer")
        if attack_range < self.width or attack_range < self.height:
            raise ValueError("attack_range cannot be smaller than sprite width or height")
        self.__attack_range = attack_range
    @property
    def unit_type(self):
        return self.__unit_type
    @unit_type.setter
    def unit_type(self, unit_type):
        if unit_type is None:
            raise ValueError("unit_type cannot be blank")
        if not isinstance(unit_type, str):
            raise ValueError("unit_type must be a string")
        if unit_type not in ["melee", "ranged", "projectile"]:
            raise ValueError("unit_type must be melee, ranged, or projectile")
        self.__unit_type = unit_type

    # unit state variables
    @property
    def team(self):
        return self.__team
    @team.setter
    def team(self, team):
        if team is None:
            raise ValueError("team cannot be blank")
        if not isinstance(team, str):
            raise ValueError("team must be a string")
        if team not in ['player', 'enemy']:
            raise ValueError("team must be 'player' or 'enemy'")
        self.__team = team
    @property
    def selected(self):
        return self.__selected
    @selected.setter
    def selected(self, selected):
        if selected is None:
            raise ValueError("selected cannot be blank")
        if not isinstance(selected, bool):
            raise ValueError("selected must be True or False")
        self.__selected = selected
    @property
    def doing(self):
        return self.__doing
    @doing.setter
    def doing(self, doing):
        if doing is None:
            raise ValueError("doing cannot be blank")
        if not isinstance(doing, str):
            raise ValueError("doing must be a string")
        if doing not in ['idle', 'walk', 'action', 'death']:
            raise ValueError("doing must be 'idle', 'walk', 'action', or 'death'")
        self.__doing = doing
    @property
    def in_combat_with(self):
        return self.__in_combat_with
    @in_combat_with.setter
    def in_combat_with(self, in_combat_with):
        if in_combat_with is not None:
            if not isinstance(in_combat_with, Entity):
                raise ValueError("in_combat_with must be an Entity or None")
            if in_combat_with.unit_type == 'projectile':
                raise ValueError("in_combat_with cannot be a projectile")
        self.__in_combat_with = in_combat_with
    @property
    def dead(self):
        return self.__dead
    @dead.setter
    def dead(self, dead):
        if dead is None:
            raise ValueError("dead cannot be blank")
        if not isinstance(dead, bool):
            raise ValueError("dead must be True or False")
        self.__dead = dead
    @property
    def location(self):
        return self.__location
    @location.setter
    def location(self, location):
        if location is None:
            raise ValueError("location cannot be blank")
        if not isinstance(location, tuple):
            raise ValueError("location must be a tuple")
        if len(location) != 2:
            raise ValueError("location must contain two integers")
        if not isinstance(location[0], int) or not isinstance(location[1], int):
            raise ValueError("location must contain two integers")
        self.__location = location
    @property
    def destination(self):
        return self.__destination
    @destination.setter
    def destination(self, destination):
        if destination is None:
            raise ValueError("destination cannot be blank")
        if not isinstance(destination, tuple):
            raise ValueError("destination must be a tuple")
        if len(destination) != 2:
            raise ValueError("destination must contain two integers")
        if not isinstance(destination[0], int) or not isinstance(destination[1], int):
            raise ValueError("destination must contain two integers")
        self.__destination = destination
    @property
    def direction(self):
        return self.__direction
    @direction.setter
    def direction(self, direction):
        if direction is None:
            raise ValueError("direction cannot be blank")
        if not isinstance(direction, int):
            raise ValueError("direction must be an integer")
        if direction not in [1, -1]:
            raise ValueError("direction must be 1 (Right) or -1 (Left)")
        self.__direction = direction

    # spritesheet and animation frame variables
    @property
    def frame_number(self):
        return self.__frame_number
    @frame_number.setter
    def frame_number(self, frame_number):
        if frame_number is None:
            raise ValueError("frame_number cannot be blank")
        if not isinstance(frame_number, int):
            raise ValueError("frame_number must be an integer")
        if frame_number < 0:
            raise ValueError("frame_number cannot be negative")
        self.__frame_number = frame_number
    @property
    def width(self):
        return self.__width
    @width.setter
    def width(self, width):
        if width is None:
            raise ValueError("width cannot be blank")
        if not isinstance(width, int):
            raise ValueError("width must be an integer")
        if width <= 0:
            raise ValueError("width must be greater than 0")
        self.__width = width
    @property
    def height(self):
        return self.__height
    @height.setter
    def height(self, height):
        if height is None:
            raise ValueError("height cannot be blank")
        if not isinstance(height, int):
            raise ValueError("height must be an integer")
        if height <= 0:
            raise ValueError("height must be greater than 0")
        self.__height = height
    @property
    def idle_frame_set(self):
        return self.__idle_frame_set
    @idle_frame_set.setter
    def idle_frame_set(self, idle_frame_set):
        if idle_frame_set is None:
            raise ValueError("idle_frame_set cannot be blank")
        if not isinstance(idle_frame_set, list):
            raise ValueError("idle_frame_set must be a list")
        self.__idle_frame_set = idle_frame_set
    @property
    def walk_frame_set(self):
        return self.__walk_frame_set
    @walk_frame_set.setter
    def walk_frame_set(self, walk_frame_set):
        if walk_frame_set is None:
            raise ValueError("walk_frame_set cannot be blank")
        if not isinstance(walk_frame_set, list):
            raise ValueError("walk_frame_set must be a list")
        self.__walk_frame_set = walk_frame_set
    @property
    def action_frame_set(self):
        return self.__action_frame_set
    @action_frame_set.setter
    def action_frame_set(self, action_frame_set):
        if action_frame_set is None:
            raise ValueError("action_frame_set cannot be blank")
        if not isinstance(action_frame_set, list):
            raise ValueError("action_frame_set must be a list")
        self.__action_frame_set = action_frame_set
    @property
    def death_frame_set(self):
        return self.__death_frame_set
    @death_frame_set.setter
    def death_frame_set(self, death_frame_set):
        if death_frame_set is None:
            raise ValueError("death_frame_set cannot be blank")
        if not isinstance(death_frame_set, list):
            raise ValueError("death_frame_set must be a list")
        self.__death_frame_set = death_frame_set

    def add_idle_frame_set(self, spritesheet, start_frame, end_frame, row, width, height):   # pylint: disable=too-many-arguments
        """Method to add new sprite frames to the idle frame set.

        Args:
            spritesheet (str): Path to the spritesheet image.
            start_frame (int): The starting frame of group to be loaded.
            end_frame (int): The ending frame of group to be loaded.
            row (int): The row of the spritesheet to look in.
            width (int): The width of each sprite on the spritesheet.
            height (int): The height of each sprite on the spritesheet.
        """
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(start_frame, end_frame):
            frame = self.sprite_sheet.get_image(i, row, width, height)
            self.__idle_frame_set.append(frame)

    def add_walk_frame_set(self, spritesheet, start_frame, end_frame, row, width, height):   # pylint: disable=too-many-arguments
        """Method to add new sprite frames to the walk frame set.

        Args:
            spritesheet (str): Path to the spritesheet image.
            start_frame (int): The starting frame of group to be loaded.
            end_frame (int): The ending frame of group to be loaded.
            row (int): The row of the spritesheet to look in.
            width (int): The width of each sprite on the spritesheet.
            height (int): The height of each sprite on the spritesheet.
        """
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(start_frame, end_frame):
            frame = self.sprite_sheet.get_image(i, row, width, height)
            self.__walk_frame_set.append(frame)
    def add_action_frame_set(self, spritesheet, start_frame, end_frame, row, width, height):  # pylint: disable=too-many-arguments
        """Method to add new sprite frames to the action frame set.

        Args:
            spritesheet (str): Path to the spritesheet image.
            start_frame (int): The starting frame of group to be loaded.
            end_frame (int): The ending frame of group to be loaded.
            row (int): The row of the spritesheet to look in.
            width (int): The width of each sprite on the spritesheet.
            height (int): The height of each sprite on the spritesheet.
        """
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(start_frame, end_frame):
            frame = self.sprite_sheet.get_image(i, row, width, height)
            self.__action_frame_set.append(frame)
    def add_death_frame_set(self, spritesheet, start_frame, end_frame, row, width, height):  # pylint: disable=too-many-arguments
        """Method to add new sprite frames to the death frame set.

        Args:
            spritesheet (str): Path to the spritesheet image.
            start_frame (int): The starting frame of group to be loaded.
            end_frame (int): The ending frame of group to be loaded.
            row (int): The row of the spritesheet to look in.
            width (int): The width of each sprite on the spritesheet.
            height (int): The height of each sprite on the spritesheet.
        """
        sprite_sheet_image = pg.image.load(spritesheet).convert_alpha()
        self.sprite_sheet = Spritesheet(sprite_sheet_image)
        for i in range(start_frame, end_frame):
            frame = self.sprite_sheet.get_image(i, row, width, height)
            self.__death_frame_set.append(frame)

    def update_frame(self, frame):
        """Method to update the displayed frame of the entity.

        Args:
            frame (Surface): Next frame of animation.
        """
        # Direction of sprite is based on direction of prev or cur movement
        if self.direction == 1:
            self.image = frame
        elif self.direction == -1:
            self.image = pg.transform.flip(frame, True, False).convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.centerx = self.location[0]
        self.rect.centery = self.location[1]

    def update_animation(self): # pylint: disable=too-many-branches
        """Method to update the animation of the entity.
        
        Iterates through the frame set of the current "doing" state.
        Wraps around to the beginning of the frame set if at the end.
        
        If the entity is dead, it only goes through the death animation once.
        Then checks if the entity is an enemy and if so, returns 100 to be
        added to the player's score. Otherwise, returns 0.

        Returns:
            int: Score to be added to the player's score.
        """
        
        # Death animation, score handling, and dead entity removal
        if self.doing == 'death':
            if self.frame_number < len(self.death_frame_set) - 1:
                self.frame_number += 1
            else:
                self.dead = True
                self.kill()
                if self.team == 'enemy':
                    return 100
                return 0
            self.update_frame(self.death_frame_set[self.frame_number])
        
        # Idle animation
        elif self.doing == 'idle':
            if self.frame_number < len(self.idle_frame_set) - 1:
                self.frame_number += 1
            else:
                self.frame_number = 0
            self.update_frame(self.idle_frame_set[self.frame_number])
        # Walk animation
        elif self.doing == 'walk':
            if self.frame_number < len(self.walk_frame_set) - 1:
                self.frame_number += 1
            else:
                self.frame_number = 0
            self.update_frame(self.walk_frame_set[self.frame_number])
        # Action animation (combat)
        elif self.doing == 'action':
            if self.frame_number < len(self.action_frame_set) - 1:
                self.frame_number += 1
            else:
                self.frame_number = 0
            self.update_frame(self.action_frame_set[self.frame_number])
        return 0

    def attack(self, entity):
        """Method to handle combat and aggro from being attacked.

        Checks if the entity is in range of the target entity.
        If so, deals damage to the target entity and sets the target entity
        as the current entity's in_combat_with if applicable. 
        If the target entity dies, sets the current entity to idle.
        

        Args:
            entity (Entity): Entity the current unit is attacking.
        """
        
        # Death check
        if entity.doing == 'death':
            self.in_combat_with = None
            self.idle()
            return
        
        
        if entity.team != self.team:
            # Range check
            x_diff = self.location[0] - entity.location[0]
            y_diff = self.location[1] - entity.location[1]
            distance = math.sqrt(x_diff**2 + y_diff**2)

            # Move in range
            if distance > self.attack_range:
                # moving towards entity loc
                self.move_to_aggro(entity.location[0], entity.location[1])
                return
            # face each other when attacking, if the other is not already in combat
            if entity.in_combat_with is None or entity.in_combat_with == self:  # pylint: disable=consider-using-in
                entity.in_combat_with = self
                if self.direction == 1:
                    entity.direction = -1
                else:
                    entity.direction = 1
                    
            # Post checks, entity changes animation to action(combat)
            self.action()
            self.in_combat_with = entity

            entity.hp -= self.attack_damage

            # Death setup
            if entity.hp <= 0:
                entity.death()
                self.idle()

    def draw(self, screen):
        """Method to draw the entity on the game screen.

        Args:
            screen (Surface): Game screen to draw the entity on.
        """
        screen.blit(self.image, self.rect)

    def ani_swap(self):
        """Method to swap the animation of the entity.
        
        Used as a prelude to most animation changes.
        """
        # Reset frame number
        self.frame_number = 0
        # No longer heading towards a destination automatically
        self.destination = self.location
        
    # head towards location until you reach it
    # or until you run into another unit
    def walk(self):
        """Method to handle walking animations.
        """
        # if not already walking(just started walking)
        # reset frame number
        # and start walking animation
        if self.doing != 'walk':
            self.doing = 'walk'
            self.frame_number = 0
        # Not fully implemented, but intended to allow fleeing
        self.in_combat_with = None
    def walk_aggro(self):
        """Method to handle walking animations during combat.
        
        Similar to walk(), but intended to be used to keep aggro.
        """
        if self.doing != 'walk':
            self.doing = 'walk'
            self.frame_number = 0
    def idle(self):
        """Method to handle idle animations.
        """
        if self.doing != 'idle':
            self.doing = 'idle'
            self.ani_swap()
        self.in_combat_with = None
    def action(self):
        """Method to handle combat animations.
        """
        if self.doing != 'action':
            self.doing = 'action'
            self.ani_swap()
    def death(self):
        """Method to handle death animations.
        """
        if self.doing != 'death':
            self.doing = 'death'
            self.ani_swap()
        self.in_combat_with = None
    def move_to(self, x, y):
        """Method to store a destination for the entity to move towards.

        Args:
            x (int): x-coordinate of the destination.
            y (int): y-coordinate of the destination.
        """
        self.walk()
        self.destination = (x, y)
    def move_to_aggro(self, x, y):
        """Similar to move_to(), but intended to be used to keep aggro.

        Args:
            x (int): x-coordinate of the destination.
            y (int): y-coordinate of the destination.
        """
        self.walk_aggro()
        self.destination = (x, y)

       # "AI" movement
    def update(self, entities, delta):  # pylint: disable=too-many-branches
        """Method to update the entity's state.
        
        Handles movement functionality, aggro range, and collision handling.
        
        Assisted by ChatGPT

        Args:
            entities (List): List of all entities in the game. 
            delta (float): Time since last frame
        """

        # Death check
        if self.doing == 'death':
            return
        if self.hp <= 0:
            self.death()
            return
        if self.doing == 'action':
            if self.in_combat_with is None or self.in_combat_with.doing == 'death':
                self.idle()
                return


        # movement (walk to destination if not already there)
        if self.destination != self.location:
            if self.doing != 'walk':
                self.walk_aggro()
                
            # Pythagorean theorem to find distance between two points
            # and then find the direction to move in
            x_diff = self.destination[0] - self.location[0]
            y_diff = self.destination[1] - self.location[1]
            distance = math.sqrt(x_diff**2 + y_diff**2)
            if distance > 10:
                direction_x = x_diff / distance
                direction_y = y_diff / distance
                
                # direction faced is based on direction of movement
                if direction_x > 0:
                    self.direction = 1
                else:
                    self.direction = -1

                # sprite movement based on delta time
                self.rect.centerx += direction_x * self.speed * delta
                
                # Collision detection (move back on collision)
                # Collision detection (x-axis)
                for entity in entities:
                    if entity != self and entity.unit_type != 'projectile':
                        if pg.sprite.collide_rect(self, entity):
                            self.rect.centerx -= direction_x * self.speed * delta

                self.rect.centery += direction_y * self.speed * delta
                # Collision detection (y-axis)
                for entity in entities:
                    if entity != self and entity.unit_type != 'projectile':
                        if pg.sprite.collide_rect(self, entity):
                            self.rect.centery -= direction_y * self.speed * delta
                            
            # in radius of destination (stop walking)
            else:
                self.idle()
        # at destination (stop walking) (redundant)
        else:
            if self.doing == 'walk':
                self.idle()
                
        # update location
        self.location = (self.rect.centerx, self.rect.centery)

        # Aggro range
        if self.in_combat_with is None: # pylint: disable=too-many-nested-blocks
            for entity in entities:
                if entity != self and entity.unit_type != 'projectile':
                    if entity.doing != 'death':
                        if entity.team != self.team:
                            x_diff = self.location[0] - entity.location[0]
                            y_diff = self.location[1] - entity.location[1]
                            distance = math.sqrt(x_diff**2 + y_diff**2)
                            # check if ranged because of 
                            # differing attack functionality
                            if self.unit_type == 'ranged':
                                if distance <= self.attack_range*1.5:
                                    self.attack(entity)
                                    break
                            # melee aggro range
                            # based off of smallest sprite size
                            # otherwise goblin will aggro from
                            # the other side of the solar system
                            if distance <= 32*6:
                                self.attack(entity)
                                break
