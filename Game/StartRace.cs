using UnityEngine.SceneManagement;

public class StartRace : ButtonAbst {

    public override void Action() {
        SceneManager.LoadScene(1);
    }
}
