1. JFrame: The JFrame class is a top-level container that represents a window with a title bar and border. It serves as the main container for Swing applications.
2. JPanel: The JPanel class is a container that can hold other components. It is often used to group and organize components within a JFrame.
3. Layout Managers: Swing provides layout managers (FlowLayout, BorderLayout, GridLayout, GridBagLayout, etc.) to arrange components within a container. Layout managers control the positioning and sizing of components.
    - GridLayout:
    ```
    f=new JFrame(); 
    // GridLayout(int rows, int columns, int hgap, int vgap)
    frameObj.setLayout(new GridLayout(3, 3, 20, 25));  
    f.setSize(300,300);    
    f.setVisible(true);    
    ```
4. Swing Components: Various components are available in Swing, including:
    - JButton: A clickable button.
    - JTextField: A single-line text field for user input.
    - JLabel: A display area for a short text string or an image.
    - JCheckBox: A box that can be checked or unchecked.
    - JRadioButton: A radio button that belongs to a group of mutually exclusive buttons.
    - JComboBox: A drop-down list of items.
    - JTextArea: A multi-line area for displaying/editing text.
    - JScrollPane: A scrollable view of another component.