using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

// This is the code for your desktop app.
// Press Ctrl+F5 (or go to Debug > Start Without Debugging) to run your app.

namespace SharpMandelbrot
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            // Click on the link below to continue learning how to build a desktop app using WinForms!
            System.Diagnostics.Process.Start("http://aka.ms/dotnet-get-started-desktop");

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Thanks!");
        }

        private void GenerateFractal(object sender, EventArgs e)
        {
            Pixel lPixel = new Pixel(25, 26, 27);

            FractalCreator lfrac = new FractalCreator(800, 600, 10000);
            lfrac.addColorRange(0.0, 0.10, Color.FromArgb( 0, 0, 254));
            lfrac.addColorRange(0.10, 0.25, Color.FromArgb( 0, 128, 255));
            lfrac.addColorRange(0.25, 0.75, Color.FromArgb( 0, 255, 255));
            lfrac.addColorRange(0.75, 1.0, Color.FromArgb( 255, 255, 255));
            lfrac.addZoom(new Zoom(295, 600 - 202, 0.1));
            lfrac.addZoom(new Zoom(288, 600 - 304, 0.01));
            lfrac.run("test.bmp");

        }
    }
}
