package fr.ensim.dp.map.player.event;

public interface IState {

    void stop(Player player);

    void play(Player player);

    void pause(Player player);

    void forward(Player player);

    void backward(Player player);
}
