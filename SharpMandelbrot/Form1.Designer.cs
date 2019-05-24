namespace SharpMandelbrot
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Generate = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripProgressBar1 = new System.Windows.Forms.ToolStripProgressBar();
            this.numericUpDownIterations = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.FractalSize = new System.Windows.Forms.GroupBox();
            this.HeightLabel = new System.Windows.Forms.Label();
            this.HeightNumericUpDown = new System.Windows.Forms.NumericUpDown();
            this.WidthLabel = new System.Windows.Forms.Label();
            this.WidthNumericUpDown = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.statusStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownIterations)).BeginInit();
            this.FractalSize.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.HeightNumericUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.WidthNumericUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // Generate
            // 
            this.Generate.Location = new System.Drawing.Point(12, 12);
            this.Generate.Name = "Generate";
            this.Generate.Size = new System.Drawing.Size(124, 27);
            this.Generate.TabIndex = 4;
            this.Generate.Text = "Generate";
            this.Generate.UseVisualStyleBackColor = true;
            this.Generate.Click += new System.EventHandler(this.GenerateFractal);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Location = new System.Drawing.Point(12, 78);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(800, 600);
            this.pictureBox1.TabIndex = 5;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.SizeChanged += new System.EventHandler(this.OnSizeChanged);
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ShowPosition);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.toolStripProgressBar1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 610);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(848, 22);
            this.statusStrip1.TabIndex = 6;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(118, 17);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // toolStripProgressBar1
            // 
            this.toolStripProgressBar1.Name = "toolStripProgressBar1";
            this.toolStripProgressBar1.Size = new System.Drawing.Size(100, 16);
            // 
            // numericUpDownIterations
            // 
            this.numericUpDownIterations.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownIterations.Location = new System.Drawing.Point(215, 19);
            this.numericUpDownIterations.Maximum = new decimal(new int[] {
            1000000,
            0,
            0,
            0});
            this.numericUpDownIterations.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownIterations.Name = "numericUpDownIterations";
            this.numericUpDownIterations.Size = new System.Drawing.Size(120, 20);
            this.numericUpDownIterations.TabIndex = 7;
            this.numericUpDownIterations.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDownIterations.ValueChanged += new System.EventHandler(this.OnIterationsChange);
            this.numericUpDownIterations.Scroll += new System.Windows.Forms.ScrollEventHandler(this.OnScroll);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(142, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Nb Iterations";
            // 
            // FractalSize
            // 
            this.FractalSize.Controls.Add(this.HeightLabel);
            this.FractalSize.Controls.Add(this.HeightNumericUpDown);
            this.FractalSize.Controls.Add(this.WidthLabel);
            this.FractalSize.Controls.Add(this.WidthNumericUpDown);
            this.FractalSize.Location = new System.Drawing.Point(369, 18);
            this.FractalSize.Name = "FractalSize";
            this.FractalSize.Size = new System.Drawing.Size(306, 54);
            this.FractalSize.TabIndex = 9;
            this.FractalSize.TabStop = false;
            this.FractalSize.Text = "Fractal Size";
            // 
            // HeightLabel
            // 
            this.HeightLabel.AutoSize = true;
            this.HeightLabel.Location = new System.Drawing.Point(161, 28);
            this.HeightLabel.Name = "HeightLabel";
            this.HeightLabel.Size = new System.Drawing.Size(38, 13);
            this.HeightLabel.TabIndex = 15;
            this.HeightLabel.Text = "Height";
            // 
            // HeightNumericUpDown
            // 
            this.HeightNumericUpDown.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.HeightNumericUpDown.Location = new System.Drawing.Point(202, 26);
            this.HeightNumericUpDown.Maximum = new decimal(new int[] {
            1000000,
            0,
            0,
            0});
            this.HeightNumericUpDown.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.HeightNumericUpDown.Name = "HeightNumericUpDown";
            this.HeightNumericUpDown.Size = new System.Drawing.Size(64, 20);
            this.HeightNumericUpDown.TabIndex = 14;
            this.HeightNumericUpDown.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.HeightNumericUpDown.ValueChanged += new System.EventHandler(this.HeigthValueChanged);
            // 
            // WidthLabel
            // 
            this.WidthLabel.AutoSize = true;
            this.WidthLabel.Location = new System.Drawing.Point(35, 28);
            this.WidthLabel.Name = "WidthLabel";
            this.WidthLabel.Size = new System.Drawing.Size(35, 13);
            this.WidthLabel.TabIndex = 13;
            this.WidthLabel.Text = "Width";
            this.WidthLabel.Click += new System.EventHandler(this.WidthValueChanged);
            // 
            // WidthNumericUpDown
            // 
            this.WidthNumericUpDown.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.WidthNumericUpDown.Location = new System.Drawing.Point(76, 26);
            this.WidthNumericUpDown.Maximum = new decimal(new int[] {
            1000000,
            0,
            0,
            0});
            this.WidthNumericUpDown.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.WidthNumericUpDown.Name = "WidthNumericUpDown";
            this.WidthNumericUpDown.Size = new System.Drawing.Size(64, 20);
            this.WidthNumericUpDown.TabIndex = 12;
            this.WidthNumericUpDown.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.WidthNumericUpDown.ValueChanged += new System.EventHandler(this.WidthValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(848, 632);
            this.Controls.Add(this.FractalSize);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericUpDownIterations);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.Generate);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownIterations)).EndInit();
            this.FractalSize.ResumeLayout(false);
            this.FractalSize.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.HeightNumericUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.WidthNumericUpDown)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button Generate;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.NumericUpDown numericUpDownIterations;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ToolStripProgressBar toolStripProgressBar1;
        private System.Windows.Forms.GroupBox FractalSize;
        private System.Windows.Forms.Label WidthLabel;
        private System.Windows.Forms.NumericUpDown WidthNumericUpDown;
        private System.Windows.Forms.Label HeightLabel;
        private System.Windows.Forms.NumericUpDown HeightNumericUpDown;
    }
}

