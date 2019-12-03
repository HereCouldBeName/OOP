using UnityEngine;

public class TrafficLights : Timer {

    [SerializeField]private GameObject[] lights;
    [SerializeField]private Person[] person;
    private int index = 0 ;

    protected override void timerDo() {
        if (index > 0) {
            if (index < 3) {
                lights[index].gameObject.SetActive(true);
                if (index == 2)
                    StartTimer(0.2f);
                else
                    StartTimer(2f);
                index++;
            } else {
                for (int i = 0; i < 3; i++) {
                    lights[i].gameObject.SetActive(false);
                }
                person[0].StartRace();
                person[1].StartRace();
                index = 0;
            }
        }
    }

    private void StartCountdown() {
        lights[0].gameObject.SetActive(true);
        index = 1;
        StartTimer(2f);
    }

    private void Awake() {
        StartCountdown();    
    }
}
