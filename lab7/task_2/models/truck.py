from .vehicle import Vehicle
from typing import Any
class Truck(Vehicle):

    def __init__(self, make: str, model: str, year: int, bed_length: float) -> None:
        super().__init__(make, model, year)
        self.bed_length = bed_length
        self.cargo: list[Any] = []

    def start(self) -> str:
        self.running = True
        return f"{self.info()} truck started. Check load and secure cargo."

    def load_cargo(self, item: Any) -> str:
        self.cargo.append(item)
        return f"Loaded {item} into {self.info()} bed."

    def unload_cargo(self) -> str:
        if not self.cargo:
            return f"No cargo to unload from {self.info()}."
        unloaded = ", ".join(map(str, self.cargo))
        self.cargo.clear()
        return f"Unloaded: {unloaded} from {self.info()}."

    def __str__(self) -> str:
        state = "running" if self.running else "stopped"
        cargo_count = len(self.cargo)
        return (
            f"{self.info()} Truck bed {self.bed_length}ft, cargo {cargo_count} items "
            f"({state})"
        )
