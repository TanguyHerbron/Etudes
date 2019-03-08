package fr.ensim.dp.map.player.event;

public class PlayState extends NullStateException {

    @Override
    public void forward(Player player) throws IllegalStateException {
        player.setState(new ForwardState());
    }

    @Override
    public void backward(Player player) throws IllegalStateException {
        player.setState(new BackwardState());
    }

    @Override
    public void stop(Player player) throws IllegalStateException {
        player.setState(new StopState());
    }

    @Override
    public void pause(Player player) throws IllegalStateException {
        player.setState(new PauseState());
    }
}
