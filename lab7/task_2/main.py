from models import Vehicle, Car, Truck


def main() -> None:
    v = Vehicle("Generic", "ModelX", 2020)
    car = Car("Toyota", "Corolla", 2021, num_doors=4)
    truck = Truck("Ford", "F-150", 2019, bed_length=6.5)

    fleet = [v, car, truck]

    print("Fleet overview:")
    for vehicle in fleet:
        print("-", vehicle)
        print("  Start:", vehicle.start())
        print("  State after start:", vehicle)

    print("\nCar actions:")
    print(" ", car.open_trunk())
    print(" ", car)

    print("\nTruck actions:")
    print(" ", truck.load_cargo("Lumber"))
    print(" ", truck.load_cargo("Toolbox"))
    print(" ", truck)
    print(" ", truck.unload_cargo())
    print(" ", truck)

    print("\nStopping all vehicles:")
    for vehicle in fleet:
        print(" ", vehicle.stop(), "|", vehicle)


if __name__ == "__main__":
    main()
