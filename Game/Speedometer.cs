using UnityEngine;

using UnityEngine.UI;

public class Speedometer : MonoBehaviour
{
    private Text speedTxt;

    public void SetSpeedUI(float _speed)
    {
        speedTxt.text = "Speed: " + _speed.ToString();
    }

    void Start()
    {
        speedTxt = GetComponent<Text>();
    }
}
