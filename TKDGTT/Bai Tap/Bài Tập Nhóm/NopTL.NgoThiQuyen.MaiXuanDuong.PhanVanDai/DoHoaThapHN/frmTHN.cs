using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Thaphanoi
{
    public partial class frmTHN : Form
    {
        TimeSpan time;
        int moveCount;
        PictureBox[] disks;
        Stack<PictureBox> disksA, disksB, disksC, firstClickedDisks, secondClickdDisks;
        const int FIRSTY = 394, DISKHEIGHT = 20, DISTXFROMROOTODISK = 11;

        public frmTHN()
        {
            InitializeComponent();
            disks = new PictureBox[] { pic1, pic2, pic3, pic4, pic5, pic6, pic7, pic8 }; //mảng 1 chiều chứa các tham chiếu đến các đĩa
            picRodA.Tag = disksA = new Stack<PictureBox>();
            picRodB.Tag = disksB = new Stack<PictureBox>();
            picRodC.Tag = disksC = new Stack<PictureBox>();
        }

        private void btnShowRule_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Luật chơi:\n - Mỗi lần chỉ được di chuyển 1 đĩa trên cọc.\n - Đĩa nằm trên phải nhỏ hơn đĩa nằm dưới", "Luật chơi", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void tmrCountTime_Tick(object sender, EventArgs e)
        {
            time = time.Add(new TimeSpan(0, 0, 1));
            lblTime.Text = string.Format("Thời Gian: {0:00}:{1:00}:{2:00}",time.Hours, time.Minutes, time.Seconds);
        }

        private void btnGiveIn_Click(object sender, EventArgs e)
        {
            tmrCountTime.Stop();
            nudLevel.Enabled = true;
            btnGiveIn.Enabled = false;
            btnPlay.Text = "Chơi";
        }

        private void btnPlay_Click(object sender, EventArgs e)
        {
            // reset
            tmrCountTime.Stop();
            foreach (PictureBox disk in disks)
                disk.Visible = false;
            time = new TimeSpan(0);
            moveCount = 0;
            lblTime.Text = "Thời Gian: 00:00:00";
            lblMoveCount.Text = "Số Lần Di Chuyển: 0 lần";
            disksA.Clear(); disksB.Clear(); disksC.Clear();
            picRodA.BorderStyle = picRodB.BorderStyle = picRodC.BorderStyle = BorderStyle.None;
            firstClickedDisks = secondClickdDisks = null;

            // khởi tạo lại cho 1 game mới
            nudLevel.Enabled = false;
            btnGiveIn.Enabled = true;
            btnPlay.Text = "Chơi lại";
            int x = picRodA.Location.X + DISTXFROMROOTODISK, y = FIRSTY;
            for (int i = (int)nudLevel.Value - 1; i >= 0; --i, y -= DISKHEIGHT)
            {
                disks[i].Location = new Point(x, y);
                disks[i].Visible = true;
                disksA.Push(disks[i]);
            }
            tmrCountTime.Start();
        }

        private void picRod_Click(object sender, EventArgs e)
        {
            if (nudLevel.Enabled) return; // ko xử lý(đang ko chơi)
            PictureBox clickedRod = (PictureBox)sender;
            Stack<PictureBox> disksOfClickedRod = (Stack<PictureBox>)clickedRod.Tag;

            if (firstClickedDisks == null)
            {
                if (disksOfClickedRod.Count == 0) return;
                firstClickedDisks = disksOfClickedRod;
                clickedRod.BorderStyle = BorderStyle.FixedSingle;
            }
            else if (secondClickdDisks == null)
            {
                if (disksOfClickedRod == firstClickedDisks)
                {
                    firstClickedDisks = null;
                    clickedRod.BorderStyle = BorderStyle.None;
                    return;
                }
                secondClickdDisks = disksOfClickedRod;
                ProcessMovingDisk(clickedRod);
            }
        }
        private void ProcessMovingDisk(PictureBox clickedRod)
        {
           // throw new NotImplementedException();
            if (secondClickdDisks.Count == 0)
                MoveDisk(new Point(clickedRod.Location.X + DISTXFROMROOTODISK, FIRSTY));
            else
            {
                PictureBox firstTopDisk = firstClickedDisks.Peek();
                PictureBox secondTopDisk = secondClickdDisks.Peek();
                if (int.Parse(firstTopDisk.Tag.ToString()) < int.Parse(secondTopDisk.Tag.ToString()))
                    MoveDisk(new Point(secondTopDisk.Location.X, secondTopDisk.Location.Y - DISKHEIGHT));
                else
                    secondClickdDisks = null;
            }
        }
        private void MoveDisk(Point point)
        {
            // throw new NotImplementedException();
            PictureBox firstTopDisk = firstClickedDisks.Pop();
            firstTopDisk.Location = point;
            secondClickdDisks.Push(firstTopDisk);
            ++moveCount;
            lblMoveCount.Text = string.Format("Số Lần Di Chuyển: {0} lần", moveCount);
            firstClickedDisks = secondClickdDisks = null;
            picRodA.BorderStyle = picRodB.BorderStyle = picRodC.BorderStyle = BorderStyle.None;

            if (disksC.Count == nudLevel.Value)
            {
                btnGiveIn.PerformClick();
                MessageBox.Show("Chúc mừng bạn đã hoàn thành trò chơi", "Chúc mừng");
            }
        }
        private void picDisk_Click(object sender, EventArgs e)
        {
            PictureBox clickedDisk = (PictureBox)sender;
            if (disksA.Contains(clickedDisk))
                picRod_Click(picRodA, new EventArgs());
            else if (disksB.Contains(clickedDisk))
                picRod_Click(picRodB, new EventArgs());
            else
                picRod_Click(picRodC, new EventArgs());

        }
    }
}
