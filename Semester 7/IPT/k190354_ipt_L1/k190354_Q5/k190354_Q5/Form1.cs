namespace k190354_Q5
{
    public partial class Form1 : Form
    {
        public static double diagonal, distance, circum, area, radius;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double x1 = Convert.ToDouble(textBox1.Text);
            double y1 = Convert.ToDouble(textBox2.Text);
            double x2 = Convert.ToDouble(textBox3.Text);
            double y2 = Convert.ToDouble(textBox4.Text);
            distance = Math.Sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
            radius = distance;
            diagonal = distance * 2;
            circum = distance * Math.PI * 2;
            area = Math.PI * distance * distance;
            Form2 f = new Form2();
            f.Show();
        }
    }
}