package fr.ensim.dp.map.player.event;

public class NullStateException extends Throwable implements IState {

    @Override
    public void stop(Player player) throws IllegalStateException {
        throw new IllegalStateException();
    }

    @Override
    public void play(Player player) throws IllegalStateException {
        throw new IllegalStateException();
    }

    @Override
    public void pause(Player player) throws IllegalStateException {
        throw new IllegalStateException();
    }

    @Override
    public void forward(Player player) throws IllegalStateException {
        throw new IllegalStateException();
    }

    @Override
    public void backward(Player player) throws IllegalStateException {
        throw new IllegalStateException();
    }
}
