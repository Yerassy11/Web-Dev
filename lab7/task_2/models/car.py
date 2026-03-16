from .vehicle import Vehicle
class Car(Vehicle):

    def __init__(self, make: str, model: str, year: int, num_doors: int) -> None:
        super().__init__(make, model, year)
        self.num_doors = num_doors
        self.trunk_open = False

    def start(self) -> str:
        self.running = True
        return f"{self.info()} car started. Ready to drive."

    def open_trunk(self) -> str:
        self.trunk_open = True
        return f"{self.info()} trunk opened."

    def close_trunk(self) -> str:
        self.trunk_open = False
        return f"{self.info()} trunk closed."

    def __str__(self) -> str:
        trunk = "open" if self.trunk_open else "closed"
        state = "running" if self.running else "stopped"
        return f"{self.info()} Car {self.num_doors} doors, trunk {trunk} ({state})"
