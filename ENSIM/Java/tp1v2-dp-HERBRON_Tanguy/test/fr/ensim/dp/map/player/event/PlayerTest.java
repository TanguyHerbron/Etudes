package fr.ensim.dp.map.player.event;

import org.junit.Test;

import static org.junit.Assert.*;

public class PlayerTest {

    private static Player player = new Player();

    @Test(expected=IllegalStateException.class)
    public void stop() {
        player.setState(new PlayState());
        player.stop();

        assertTrue(player.getState() instanceof StopState);

        player.setState(new PauseState());
        player.stop();
    }

    @Test(expected=IllegalStateException.class)
    public void play() {
        player.setState(new StopState());
        player.play();

        assertTrue(player.getState() instanceof PlayState);

        player.setState(new PauseState());
        player.play();
    }

    @Test(expected=IllegalStateException.class)
    public void pause() {
        player.setState(new PlayState());
        player.pause();

        assertTrue(player.getState() instanceof PauseState);

        player.play();
    }

    @Test(expected=IllegalStateException.class)
    public void forward() {
        player.setState(new BackwardState());
        player.forward();

        assertTrue(player.getState() instanceof ForwardState);

        player.setState(new PlayState());
        player.forward();

        assertTrue(player.getState() instanceof ForwardState);

        player.setState(new PauseState());
        player.forward();
    }

    @Test(expected=IllegalStateException.class)
    public void backward() {
        player.setState(new ForwardState());
        player.backward();

        assertTrue(player.getState() instanceof BackwardState);

        player.setState(new PlayState());
        player.backward();

        assertTrue(player.getState() instanceof BackwardState);

        player.setState(new PauseState());
        player.backward();
    }
}