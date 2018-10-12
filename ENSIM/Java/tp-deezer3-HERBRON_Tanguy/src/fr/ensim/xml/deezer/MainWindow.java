package fr.ensim.xml.deezer;

import java.awt.EventQueue;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MainWindow {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainWindow window = new MainWindow();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainWindow() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 75);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);

		JPanel pnMainPanel;
		final JTextField tfSearchTextBox;
		JLabel lbSearchLabel;
		JButton btSearchButton;

		pnMainPanel = new JPanel();
		GridBagLayout gbMainPanel = new GridBagLayout();
		GridBagConstraints gbcMainPanel = new GridBagConstraints();
		pnMainPanel.setLayout( gbMainPanel );

		tfSearchTextBox = new JTextField( );
		gbcMainPanel.gridx = 3;
		gbcMainPanel.gridy = 1;
		gbcMainPanel.gridwidth = 7;
		gbcMainPanel.gridheight = 2;
		gbcMainPanel.fill = GridBagConstraints.BOTH;
		gbcMainPanel.weightx = 1;
		gbcMainPanel.weighty = 0;
		gbcMainPanel.anchor = GridBagConstraints.NORTH;
		gbMainPanel.setConstraints( tfSearchTextBox, gbcMainPanel );
		pnMainPanel.add( tfSearchTextBox );

		lbSearchLabel = new JLabel( "Search :"  );
		gbcMainPanel.gridx = 0;
		gbcMainPanel.gridy = 1;
		gbcMainPanel.gridwidth = 3;
		gbcMainPanel.gridheight = 2;
		gbcMainPanel.fill = GridBagConstraints.BOTH;
		gbcMainPanel.weightx = 1;
		gbcMainPanel.weighty = 1;
		gbcMainPanel.anchor = GridBagConstraints.NORTH;
		gbMainPanel.setConstraints( lbSearchLabel, gbcMainPanel );
		pnMainPanel.add( lbSearchLabel );

		btSearchButton = new JButton( "Search"  );
		gbcMainPanel.gridx = 11;
		gbcMainPanel.gridy = 1;
		gbcMainPanel.gridwidth = 5;
		gbcMainPanel.gridheight = 2;
		gbcMainPanel.fill = GridBagConstraints.BOTH;
		gbcMainPanel.weightx = 1;
		gbcMainPanel.weighty = 0;
		gbcMainPanel.anchor = GridBagConstraints.NORTH;
		gbMainPanel.setConstraints( btSearchButton, gbcMainPanel );
		pnMainPanel.add( btSearchButton );
		
		frame.add(pnMainPanel);
		
		btSearchButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				String str = tfSearchTextBox.getText();
				str = str.replaceAll("\\s", "%20");
				new Main(str);
			}
		});
	}

}
