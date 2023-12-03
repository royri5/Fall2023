class Spaceship:
    def __init__(self, name, hp, shield):
        #self.__name = name
        #self.__hp = hp
        #self.__shield = shield

        #bad but valid
        #self.set_name(name)
        #self.set_hp(hp)
        #self.set_shield(shield)

        self.name = name
    
    @property
    def name(self):
        return self.__name
    
    @name.setter
    def name(self, name):
        if not name:
            raise ValueError("Can't be None type for string.")
        self.__name = name

#bad (no name)
#s = Spaceship(None, 100, 1.0)