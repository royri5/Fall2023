"""This module contains the Ranged class.

The Ranged class is a subclass of the Entity class. It is used to create
ranged units for the game. 

Author:
    Richard Roy

Date:
    2023-12-10

Resources:
    Player ranged: https://opengameart.org/content/animated-ranger
    Enemy ranged: https://opengameart.org/content/ghost-animated
"""

import math
from entity import Entity

class Ranged(Entity):   # pylint: disable=too-many-instance-attributes
    """Class for creating ranged units.
    
    Inherits from the Entity class.
    Ranged units have a different method for attacking than melee units.

    Attributes:
        in_range (bool): A boolean value to determine if the enemy the unit is
            attacking is within range.
    """
    def __init__(self, start_location, team):    # pylint: disable=too-many-statements
        """Constructor for the Ranged class.

        Args:
            start_location (tuple): Starting location of the unit. x, y coordinates.
            team (str): The team the unit belongs to. Can be 'player' or 'enemy'.
        """
        super().__init__(start_location, team)
        self.idle_frame_set = []
        self.walk_frame_set = []
        self.action_frame_set = []
        self.death_frame_set = []
        self.frame_number = 0
        self.unit_type = 'ranged'
        self.attack_range = self.width * 3
        self.in_range = False

        # Loads the correct sprite sheet based on the team
        if team == 'player':
            self.width = 32
            self.height = 32
            self.attack_range = 130

            start_frame = 0
            end_frame = 10
            row = 0
            self.add_idle_frame_set(
                './assets/ranger spritesheet calciumtrice.png',
                start_frame, end_frame, row, self.width, self.height)
            row = 1
            self.add_idle_frame_set(
				'./assets/ranger spritesheet calciumtrice.png',
				start_frame, end_frame, row, self.width, self.height)
            row = 2
            self.add_walk_frame_set(
				'./assets/ranger spritesheet calciumtrice.png',
				start_frame, end_frame, row, self.width, self.height)
            row = 3
            self.add_action_frame_set(
				'./assets/ranger spritesheet calciumtrice.png',
				start_frame, end_frame, row, self.width, self.height)
            row = 4
            self.add_death_frame_set(
				'./assets/ranger spritesheet calciumtrice.png',
				start_frame, end_frame, row, self.width, self.height)

        # ghost sprite sheet does not have as many idle frames as ranger
        # so we will have to add the same frame multiple times to make it look
        # uniform
        elif team == 'enemy':
            self.width = 32
            self.height = 32
            self.attack_range = 130

            # frame group idle
            #start_frame = 0
            #end_frame = 3
            start_frame = 0
            end_frame = 1
            row = 2
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 1
            end_frame = 2
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 2
            end_frame = 3
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 3
            end_frame = 4
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            self.add_idle_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)

            # frame group walk
            # start_frame = 0
            # end_frame = 5
            start_frame = 0
            end_frame = 1
            row = 2
            self.add_walk_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 1
            end_frame = 2
            self.add_walk_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 2
            end_frame = 3
            self.add_walk_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 3
            end_frame = 4
            self.add_walk_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)

            # frame group action
            # start_frame = 0
            # end_frame = 5
            start_frame = 0
            end_frame = 1
            row = 1
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 1
            end_frame = 2
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 2
            end_frame = 3
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 3
            end_frame = 4
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 4
            end_frame = 5
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 5
            end_frame = 6
            self.add_action_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)

            # frame group death
            # start_frame = 0
            # end_frame = 8
            start_frame = 0
            end_frame = 1
            row = 0
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 1
            end_frame = 2
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 2
            end_frame = 3
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 3
            end_frame = 4
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 4
            end_frame = 5
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 5
            end_frame = 6
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 6
            end_frame = 7
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)
            start_frame = 7
            end_frame = 8
            self.add_death_frame_set(
				'./assets/ghostIce_all.png',
				start_frame, end_frame, row, self.width, self.height)

        start_frame = self.idle_frame_set[self.frame_number]
        self.update_frame(start_frame)

    @property
    def in_range(self):
        return self.__in_range
    @in_range.setter
    def in_range(self, value):
        if value not in [True, False]:
            raise ValueError('in_range must be True or False')
        self.__in_range = value

    def attack(self, entity):
        """Attack method for the Ranged class.
        
        Overrides the attack method in the Entity class.
        To provide different functionality for ranged units.
        Does not directly deal damage to the entity.
        Instead, focuses on moving the unit into range.
        Main method then checks for the ok(ranged unit's
        in_combat_with is an enemy) to spawn a projectile
        to deal damage to the enemy when it collides with it.

        Args:
            entity (Entity): The entity the unit is attacking.
        """
        
        # in_combat_with entity is dead
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
            if distance > self.attack_range:    # pylint: disable=no-else-return
                # moving towards entity loc
                self.in_range = False
                self.move_to_aggro(entity.location[0], entity.location[1])
                return
            else:
                self.in_range = True
            # face each other when attacking
            if entity.in_combat_with is None or entity.in_combat_with == self:  # pylint: disable=consider-using-in
                entity.in_combat_with = self
                if self.direction == 1:
                    entity.direction = -1
                else:
                    entity.direction = 1
            self.action()
            self.in_combat_with = entity

            # death setup
            if entity.hp <= 0:
                entity.death()
                self.idle()
