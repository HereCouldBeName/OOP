using UnityEngine;

public class Player : Person {

    private Car car;
    private Taxometr taxometr;
    private Speedometer speedometer;
    private GameObject canvas;

    void Start() {
        taxometr = GameObject.FindGameObjectWithTag("arrow").GetComponent("Taxometr") as Taxometr;
        speedometer = GameObject.FindGameObjectWithTag("Speedometer").GetComponent("Speedometer") as Speedometer;
        car = GetComponent("Car") as Car;
        canvas = GameObject.FindGameObjectWithTag("UIPlayer").gameObject;
    }

    public void ShowUI() {
        canvas.SetActive(true);
    }

    public void HideUI() {
        canvas.SetActive(false);
    }

    private void Update() {
        if (IsGameStart) {
            float W = Input.GetAxis("Vertical");
            bool G = Input.GetKeyDown(KeyCode.Q);
            if (W > 0) {
                car.Move();
            }
            if (G) {
                car.ShiftGearEngine();
            }
        }
        taxometr.SetPosArrow(car.GetTurnEngine());
        speedometer.SetSpeedUI(car.GetSpeed());
    }
}
