package fr.ensim.dp.map.player.event;

public class ForwardState extends NullStateException {

    @Override
    public void backward(Player player) throws IllegalStateException {
        player.setState(new BackwardState());
    }
}
