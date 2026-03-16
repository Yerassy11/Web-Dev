



class Vehicle:

    def __init__(self, make: str, model: str, year: int) -> None:
        self.make = make
        self.model = model
        self.year = year
        self.running = False

    def start(self) -> str:
        self.running = True
        return f"{self.year} {self.make} {self.model} engine started."

    def stop(self) -> str:
        self.running = False
        return f"{self.year} {self.make} {self.model} engine stopped."

    def info(self) -> str:
        return f"{self.year} {self.make} {self.model}"

    def __str__(self) -> str:
        state = "running" if self.running else "stopped"
        return f"{self.info()} ({state})"
