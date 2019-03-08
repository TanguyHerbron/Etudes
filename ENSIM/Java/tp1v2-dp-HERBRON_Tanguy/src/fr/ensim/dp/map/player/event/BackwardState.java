package fr.ensim.dp.map.player.event;

public class BackwardState extends NullStateException {

    @Override
    public void forward(Player player) throws IllegalStateException {
        player.setState(new ForwardState());
    }
}
