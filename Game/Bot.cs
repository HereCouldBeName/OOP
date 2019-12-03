public class Bot : Person {

    private Car car;

    void Start() {
        car = GetComponent("Car") as Car;
    }

    void Update() {
        if (IsGameStart) {
            car.Move();
        }
    }
}
