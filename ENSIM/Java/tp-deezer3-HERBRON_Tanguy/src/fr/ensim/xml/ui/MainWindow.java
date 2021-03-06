package fr.ensim.xml.ui;

import java.io.File;
import java.io.IOException;

import com.sun.media.jfxmedia.events.PlayerTimeListener;

import fr.ensim.xml.deezer.Runner;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.MenuButton;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;

public class MainWindow extends Application {

	private boolean useDom;
	private boolean useCustom;
	
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
		final WebEngine engine = webView.getEngine();
		final MenuButton formatButton = (MenuButton) scene.lookup("#xmlFormatSelector");
		final MenuItem domOption = formatButton.getItems().get(0);
		final MenuItem saxOption = formatButton.getItems().get(1);
		final MenuButton htmlButton = (MenuButton) scene.lookup("#htmlGeneratorSelector");
		final MenuItem customOption = htmlButton.getItems().get(0);
		final MenuItem staxOption = htmlButton.getItems().get(1);
		final Label loadingLabel = (Label) scene.lookup("#loadingLabel");
		
		final Thread uiThread = Thread.currentThread();
		
		searchTextField.setOnKeyReleased(new EventHandler<KeyEvent>() {

			@Override
			public void handle(KeyEvent event) {
				if(event.getCode() == KeyCode.ENTER)
				{
					startSearch(menuButton.getText(), searchTextField.getText(), engine, loadingLabel);
				}
			}
		});
		
		searchButton.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				startSearch(menuButton.getText(), searchTextField.getText(), engine, loadingLabel);
			}
		});
		
		xmlOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				menuButton.setText(xmlOption.getText());
				formatButton.setDisable(false);
			}
		});
		
		jsonOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				menuButton.setText(jsonOption.getText());
				formatButton.setDisable(true);
			}
		});
	
		domOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				formatButton.setText(domOption.getText());
				useDom = true;
			}
		});
		
		saxOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				formatButton.setText(saxOption.getText());
				useDom = false;
			}
		});
	
		customOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				htmlButton.setText(customOption.getText());
				useCustom = true;
			}
		});
	
		staxOption.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent event) {
				htmlButton.setText(staxOption.getText());
				useCustom = false;
			}
		});
	}
	
	public void startSearch(String menuButtonStr, final String searchStr, final WebEngine engine, final Label loadingLabel)
	{
		loadingLabel.setVisible(true);
		engine.loadContent("");
		
		if(menuButtonStr.equals("JSON"))
		{
			Thread thread = new Thread()
			{
				public void run()
				{
					Runner runner = new Runner();
					final File htmlFile = runner.start(searchStr.replaceAll("\\s", "%20"), useCustom);
					
					Platform.runLater(new Runnable(){

						@Override
						public void run() {
							engine.load(htmlFile.toURI().toString());
							loadingLabel.setVisible(false);
						}								
					});
				}
			};
			
			thread.start();
		}
		else
		{
			Thread thread = new Thread()
			{
				public void run()
				{
					Runner runner = new Runner();
					final File htmlFile = runner.start(searchStr.replaceAll("\\s", "%20"), useDom, useCustom);
					
					Platform.runLater(new Runnable(){

						@Override
						public void run() {
							engine.load(htmlFile.toURI().toString());
							loadingLabel.setVisible(false);
						}								
					});
				}
			};
			
			thread.start();
		}
	}

	public static void main(String[] args) {
		launch(args);
	}
}
