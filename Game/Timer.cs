using UnityEngine;

public abstract class Timer : MonoBehaviour {

    private double timer, delay;
    private bool isStarted;

    protected abstract void timerDo();

    protected bool GetTimerStatus() {
        return isStarted;
    }

    protected void StartTimer(float _delay) {
        isStarted = true;
        delay = _delay;
        timer = _delay;
    }

    private void Start() {
        isStarted = false;
    }

    void Update() {
		if (timer > 0)
        {
            timer -= Time.deltaTime;
        } else
        {
            timerDo();
            isStarted = false;
        }
	}
}
