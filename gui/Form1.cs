using System;
using System.Collections.Generic;
using System.ComponentModel;

using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using WeifenLuo.WinFormsUI.Docking;

namespace gui
{
    public partial class Form1 : Form
    {


        public Form1()
        {
            InitializeComponent();
            WeifenLuo.WinFormsUI.Docking.VS2012LightTheme vS2012LightTheme1 = new VS2012LightTheme();
            dockPanel1.Theme = vS2012LightTheme1;
/*
            int val = m_wrapper.callTest();
            val = m_wrapper.callTest(11234);

            iPtr = new IntPtr(m_wrapper.SDL_GetWindowID(this.Width, this.Height));

            this.Text = "Hello " + iPtr;

            SetParent(iPtr, panel1.Handle);
            SetWindowPos(iPtr, IntPtr.Zero, 0, 0, 0, 0, (SetWindowPosFlags.SWP_SHOWWINDOW | SetWindowPosFlags.SWP_NOSIZE));
            //ShowWindow(iPtr, ShowWindowCommand.SW_SHOWNORMAL);

            */
            Form2 f2 = new Form2();
            f2.Show(dockPanel1, DockState.Float);

            Form3 f3 = new Form3();
            f3.Show(dockPanel1, DockState.DockBottom);
        }


        private void panel1_Resize(object sender, EventArgs e)
        {
            /*
            SetWindowPos(iPtr, IntPtr.Zero, 0, 0, this.Width, this.Height, (SetWindowPosFlags.SWP_SHOWWINDOW));//this.Width, this.Height, 0);
            m_wrapper.resize(this.Width, this.Height);
             * */
        }
        
    }
}
