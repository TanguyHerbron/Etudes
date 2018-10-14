package fr.ensim.xml.ui;

import java.io.File;
import java.io.IOException;

import fr.ensim.xml.deezer.Runner;
import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.MenuButton;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;

public class MainWindow extends Application {

	@Override
	public void start(Stage primaryStage) throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource("MainWindow.fxml"));
		
		Scene scene = new Scene(root, 640, 400);
		primaryStage.setTitle("Deezer pour les nuls");
		primaryStage.setScene(scene);
		primaryStage.show();
		
		initiateEvents(scene);
	}
	
	private void initiateEvents(Scene scene)
	{		
		final TextField searchTextField = (TextField) scene.lookup("#searchBar");
		Button searchButton = (Button) scene.lookup("#searchButton");
		final MenuButton menuButton = (MenuButton) scene.lookup("#parserSelector");
		final MenuItem xmlOption = menuButton.getItems().get(0);
		final MenuItem jsonOption = menuButton.getItems().get(1);
		final WebView webView = (WebView) scene.lookup("#webView");
		
		searchButton.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				if(menuButton.getText().equals(jsonOption.getText()))
				{
					Runner runner = new Runner();
					File htmlFile = runner.start(searchTextField.getText().replaceAll("\\s", "%20"));
					WebEngine engine = webView.getEngine();
					engine.load(htmlFile.toURI().toString());
				}
				else
				{
					Runner runner = new Runner();
					File htmlFile = runner.start(searchTextField.getText().replaceAll("\\s", "%20"), false);
					WebEngine engine = webView.getEngine();
					engine.load(htmlFile.toURI().toString());
				}
				
			}
		});
		
		xmlOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				menuButton.setText(xmlOption.getText());
			}
		});
		
		jsonOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				menuButton.setText(jsonOption.getText());
			}
		});
	}

	public static void main(String[] args) {
		launch(args);
	}
}
