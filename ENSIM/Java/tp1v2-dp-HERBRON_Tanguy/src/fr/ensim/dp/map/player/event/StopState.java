package fr.ensim.dp.map.player.event;

public class StopState extends NullStateException {

    @Override
    public void play(Player player) throws IllegalStateException {
        player.setState(new PlayState());
    }
}
