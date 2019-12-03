using UnityEngine;

public class ButtonItem : ButtonAbst {
    [SerializeField] private int typeItem;
    [SerializeField] private string path;

    private Car car;

    public override void Action() {
        car.Tuning(path, typeItem);
    }

    private void Start() {
        car = GameObject.FindGameObjectWithTag("Player").GetComponent("Car") as Car;
    }
}
