package fr.ensim.dp.map.player.event;

public class Player {

    private IState state;

    public void setState(IState state)
    {
        this.state = state;
    }

    public IState getState()
    {
        return state;
    }

    public void stop() {
        state.stop(this);
    }

    public void play() {
        state.play(this);
    }

    public void pause() {
        state.pause(this);
    }

    public void forward() {
        state.forward(this);
    }

    public void backward() {
        state.backward(this);
    }
}
