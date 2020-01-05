namespace Thaphanoi
{
    partial class frmTHN
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
            this.components = new System.ComponentModel.Container();
            this.picRodA = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.picRodB = new System.Windows.Forms.PictureBox();
            this.label2 = new System.Windows.Forms.Label();
            this.picRodC = new System.Windows.Forms.PictureBox();
            this.label3 = new System.Windows.Forms.Label();
            this.pic1 = new System.Windows.Forms.PictureBox();
            this.pic2 = new System.Windows.Forms.PictureBox();
            this.pic8 = new System.Windows.Forms.PictureBox();
            this.pic7 = new System.Windows.Forms.PictureBox();
            this.pic6 = new System.Windows.Forms.PictureBox();
            this.pic5 = new System.Windows.Forms.PictureBox();
            this.pic4 = new System.Windows.Forms.PictureBox();
            this.pic3 = new System.Windows.Forms.PictureBox();
            this.lblTime = new System.Windows.Forms.Label();
            this.tmrCountTime = new System.Windows.Forms.Timer(this.components);
            this.lblMoveCount = new System.Windows.Forms.Label();
            this.nudLevel = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.btnPlay = new System.Windows.Forms.Button();
            this.btnGiveIn = new System.Windows.Forms.Button();
            this.btnShowRule = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picRodA)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picRodB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picRodC)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudLevel)).BeginInit();
            this.SuspendLayout();
            // 
            // picRodA
            // 
            this.picRodA.Image = global::Thaphanoi.Properties.Resources._1;
            this.picRodA.Location = new System.Drawing.Point(95, 207);
            this.picRodA.Name = "picRodA";
            this.picRodA.Size = new System.Drawing.Size(236, 242);
            this.picRodA.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picRodA.TabIndex = 0;
            this.picRodA.TabStop = false;
            this.picRodA.Click += new System.EventHandler(this.picRod_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(200, 452);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(27, 25);
            this.label1.TabIndex = 1;
            this.label1.Text = "A";
            // 
            // picRodB
            // 
            this.picRodB.Image = global::Thaphanoi.Properties.Resources._1;
            this.picRodB.Location = new System.Drawing.Point(328, 207);
            this.picRodB.Name = "picRodB";
            this.picRodB.Size = new System.Drawing.Size(236, 242);
            this.picRodB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picRodB.TabIndex = 0;
            this.picRodB.TabStop = false;
            this.picRodB.Click += new System.EventHandler(this.picRod_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(433, 452);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 25);
            this.label2.TabIndex = 1;
            this.label2.Text = "B";
            // 
            // picRodC
            // 
            this.picRodC.Image = global::Thaphanoi.Properties.Resources._1;
            this.picRodC.Location = new System.Drawing.Point(560, 207);
            this.picRodC.Name = "picRodC";
            this.picRodC.Size = new System.Drawing.Size(236, 242);
            this.picRodC.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picRodC.TabIndex = 0;
            this.picRodC.TabStop = false;
            this.picRodC.Click += new System.EventHandler(this.picRod_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(665, 452);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(28, 25);
            this.label3.TabIndex = 1;
            this.label3.Text = "C";
            // 
            // pic1
            // 
            this.pic1.Image = global::Thaphanoi.Properties.Resources.so1;
            this.pic1.Location = new System.Drawing.Point(118, 394);
            this.pic1.Name = "pic1";
            this.pic1.Size = new System.Drawing.Size(191, 20);
            this.pic1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic1.TabIndex = 2;
            this.pic1.TabStop = false;
            this.pic1.Tag = "1";
            this.pic1.Visible = false;
            this.pic1.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // pic2
            // 
            this.pic2.Image = global::Thaphanoi.Properties.Resources.so2;
            this.pic2.Location = new System.Drawing.Point(351, 394);
            this.pic2.Name = "pic2";
            this.pic2.Size = new System.Drawing.Size(191, 20);
            this.pic2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic2.TabIndex = 2;
            this.pic2.TabStop = false;
            this.pic2.Tag = "2";
            this.pic2.Visible = false;
            this.pic2.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // pic8
            // 
            this.pic8.Image = global::Thaphanoi.Properties.Resources.so8;
            this.pic8.Location = new System.Drawing.Point(583, 394);
            this.pic8.Name = "pic8";
            this.pic8.Size = new System.Drawing.Size(191, 20);
            this.pic8.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic8.TabIndex = 2;
            this.pic8.TabStop = false;
            this.pic8.Tag = "8";
            this.pic8.Visible = false;
            this.pic8.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // pic7
            // 
            this.pic7.Image = global::Thaphanoi.Properties.Resources.so7;
            this.pic7.Location = new System.Drawing.Point(583, 379);
            this.pic7.Name = "pic7";
            this.pic7.Size = new System.Drawing.Size(191, 20);
            this.pic7.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic7.TabIndex = 2;
            this.pic7.TabStop = false;
            this.pic7.Tag = "7";
            this.pic7.Visible = false;
            this.pic7.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // pic6
            // 
            this.pic6.Image = global::Thaphanoi.Properties.Resources.so6;
            this.pic6.Location = new System.Drawing.Point(583, 342);
            this.pic6.Name = "pic6";
            this.pic6.Size = new System.Drawing.Size(191, 20);
            this.pic6.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic6.TabIndex = 2;
            this.pic6.TabStop = false;
            this.pic6.Tag = "6";
            this.pic6.Visible = false;
            this.pic6.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // pic5
            // 
            this.pic5.Image = global::Thaphanoi.Properties.Resources.so5;
            this.pic5.Location = new System.Drawing.Point(583, 316);
            this.pic5.Name = "pic5";
            this.pic5.Size = new System.Drawing.Size(191, 20);
            this.pic5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic5.TabIndex = 2;
            this.pic5.TabStop = false;
            this.pic5.Tag = "5";
            this.pic5.Visible = false;
            this.pic5.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // pic4
            // 
            this.pic4.Image = global::Thaphanoi.Properties.Resources.so4;
            this.pic4.Location = new System.Drawing.Point(583, 290);
            this.pic4.Name = "pic4";
            this.pic4.Size = new System.Drawing.Size(191, 20);
            this.pic4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic4.TabIndex = 2;
            this.pic4.TabStop = false;
            this.pic4.Tag = "4";
            this.pic4.Visible = false;
            this.pic4.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // pic3
            // 
            this.pic3.Image = global::Thaphanoi.Properties.Resources.so3;
            this.pic3.Location = new System.Drawing.Point(583, 264);
            this.pic3.Name = "pic3";
            this.pic3.Size = new System.Drawing.Size(191, 20);
            this.pic3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pic3.TabIndex = 2;
            this.pic3.TabStop = false;
            this.pic3.Tag = "3";
            this.pic3.Visible = false;
            this.pic3.Click += new System.EventHandler(this.picDisk_Click);
            // 
            // lblTime
            // 
            this.lblTime.AutoSize = true;
            this.lblTime.BackColor = System.Drawing.Color.White;
            this.lblTime.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTime.ForeColor = System.Drawing.Color.Blue;
            this.lblTime.Location = new System.Drawing.Point(352, 22);
            this.lblTime.Name = "lblTime";
            this.lblTime.Size = new System.Drawing.Size(188, 27);
            this.lblTime.TabIndex = 3;
            this.lblTime.Text = "Thời Gian: 00:00:00";
            // 
            // tmrCountTime
            // 
            this.tmrCountTime.Interval = 1000;
            this.tmrCountTime.Tick += new System.EventHandler(this.tmrCountTime_Tick);
            // 
            // lblMoveCount
            // 
            this.lblMoveCount.AutoSize = true;
            this.lblMoveCount.BackColor = System.Drawing.Color.White;
            this.lblMoveCount.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblMoveCount.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblMoveCount.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.lblMoveCount.Location = new System.Drawing.Point(340, 60);
            this.lblMoveCount.Name = "lblMoveCount";
            this.lblMoveCount.Size = new System.Drawing.Size(212, 27);
            this.lblMoveCount.TabIndex = 3;
            this.lblMoveCount.Text = "Số lần di chuyển: 0 lần";
            // 
            // nudLevel
            // 
            this.nudLevel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nudLevel.Location = new System.Drawing.Point(462, 96);
            this.nudLevel.Maximum = new decimal(new int[] {
            8,
            0,
            0,
            0});
            this.nudLevel.Minimum = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.nudLevel.Name = "nudLevel";
            this.nudLevel.Size = new System.Drawing.Size(43, 30);
            this.nudLevel.TabIndex = 4;
            this.nudLevel.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(391, 98);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(68, 25);
            this.label4.TabIndex = 5;
            this.label4.Text = "Số đĩa";
            // 
            // btnPlay
            // 
            this.btnPlay.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPlay.Location = new System.Drawing.Point(270, 146);
            this.btnPlay.Name = "btnPlay";
            this.btnPlay.Size = new System.Drawing.Size(100, 30);
            this.btnPlay.TabIndex = 6;
            this.btnPlay.Text = "Chơi";
            this.btnPlay.UseVisualStyleBackColor = true;
            this.btnPlay.Click += new System.EventHandler(this.btnPlay_Click);
            // 
            // btnGiveIn
            // 
            this.btnGiveIn.Enabled = false;
            this.btnGiveIn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGiveIn.Location = new System.Drawing.Point(388, 146);
            this.btnGiveIn.Name = "btnGiveIn";
            this.btnGiveIn.Size = new System.Drawing.Size(117, 30);
            this.btnGiveIn.TabIndex = 6;
            this.btnGiveIn.Text = "Chịu thua";
            this.btnGiveIn.UseVisualStyleBackColor = true;
            this.btnGiveIn.Click += new System.EventHandler(this.btnGiveIn_Click);
            // 
            // btnShowRule
            // 
            this.btnShowRule.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowRule.Location = new System.Drawing.Point(523, 146);
            this.btnShowRule.Name = "btnShowRule";
            this.btnShowRule.Size = new System.Drawing.Size(100, 30);
            this.btnShowRule.TabIndex = 6;
            this.btnShowRule.Text = "Luật chơi";
            this.btnShowRule.UseVisualStyleBackColor = true;
            this.btnShowRule.Click += new System.EventHandler(this.btnShowRule_Click);
            // 
            // frmTHN
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(890, 481);
            this.Controls.Add(this.btnShowRule);
            this.Controls.Add(this.btnGiveIn);
            this.Controls.Add(this.btnPlay);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.nudLevel);
            this.Controls.Add(this.lblMoveCount);
            this.Controls.Add(this.lblTime);
            this.Controls.Add(this.pic3);
            this.Controls.Add(this.pic4);
            this.Controls.Add(this.pic5);
            this.Controls.Add(this.pic6);
            this.Controls.Add(this.pic7);
            this.Controls.Add(this.pic8);
            this.Controls.Add(this.pic2);
            this.Controls.Add(this.pic1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.picRodC);
            this.Controls.Add(this.picRodB);
            this.Controls.Add(this.picRodA);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.Name = "frmTHN";
            this.Text = "Tháp Hà Nội- K55A3 Toán Tin";
            ((System.ComponentModel.ISupportInitialize)(this.picRodA)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picRodB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picRodC)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pic3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudLevel)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox picRodA;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox picRodB;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox picRodC;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.PictureBox pic1;
        private System.Windows.Forms.PictureBox pic2;
        private System.Windows.Forms.PictureBox pic8;
        private System.Windows.Forms.PictureBox pic7;
        private System.Windows.Forms.PictureBox pic6;
        private System.Windows.Forms.PictureBox pic5;
        private System.Windows.Forms.PictureBox pic4;
        private System.Windows.Forms.PictureBox pic3;
        private System.Windows.Forms.Label lblTime;
        private System.Windows.Forms.Timer tmrCountTime;
        private System.Windows.Forms.Label lblMoveCount;
        private System.Windows.Forms.NumericUpDown nudLevel;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnPlay;
        private System.Windows.Forms.Button btnGiveIn;
        private System.Windows.Forms.Button btnShowRule;
    }
}

