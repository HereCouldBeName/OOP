using UnityEngine;

public class Tuning : MonoBehaviour {

    [SerializeField] private GameObject mainButton;
    [SerializeField] private GameObject mainTuning;
    [SerializeField] private GameObject frontBumperTuning;
    [SerializeField] private GameObject backBumperTuning;
    [SerializeField] private GameObject whellTuning;
    [SerializeField] private GameObject otherTuning;

    //private Car car;

    public void ShowMainTuning() {
        mainTuning.SetActive(true);
        mainButton.SetActive(false);
    }

    public void HideMainTuning() {
        mainTuning.SetActive(false);
        frontBumperTuning.SetActive(false);
        backBumperTuning.SetActive(false);
        whellTuning.SetActive(false);
        otherTuning.SetActive(false);
        mainButton.SetActive(true);
    }

    public void ShowHideItem(int cell) {
        switch (cell) { 
        case 0:
            frontBumperTuning.SetActive(!frontBumperTuning.active);
            break;
        case 1:
            backBumperTuning.SetActive(!backBumperTuning.active);
            break;
        case 2:
            whellTuning.SetActive(!whellTuning.active);
            break;
        case 3:
            otherTuning.SetActive(!otherTuning.active);
            break;
        }
    }
}
