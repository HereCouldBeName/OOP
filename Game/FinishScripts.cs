using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class FinishScripts : Timer {

    private bool isEnemy = false;

    [SerializeField] private Text text;

    private void OnTriggerEnter(Collider other) {
        if (other.tag == "Enemy") {
            isEnemy = true;
        }
        if (other.tag == "Player") {
            text.gameObject.SetActive(true);
            if (!isEnemy) {
                text.text = "You Win";
            } else {
                text.text = "You Lose";
            }
            StartTimer(0.5f);
        }
    }

    protected override void timerDo() {
        if(GetTimerStatus())
            SceneManager.LoadScene(0);
    }
}
