using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace gui
{
    public partial class Form2 : DockContent
    {
        UnmanagedWrapper m_wrapper;

        [DllImport("user32.dll", SetLastError = true)]
        static extern bool SetWindowPos(IntPtr handle, IntPtr handleAfter, int x, int y, int cx, int cy, SetWindowPosFlags flags);
        [DllImport("user32.dll", SetLastError = true)]
        static extern IntPtr SetParent(IntPtr child, IntPtr newParent);
        [DllImport("user32.dll", SetLastError = true)]
        static extern bool ShowWindow(IntPtr handle, ShowWindowCommand command);

        enum SetWindowPosFlags : uint
        {
            SWP_SHOWWINDOW = 0x0040,
            SWP_NOSIZE = 0x0001
        }

        private enum ShowWindowCommand : int
        {
            SW_HIDE = 0,
            SW_SHOW = 5,
            SW_SHOWNA = 8,
            SW_SHOWNORMAL = 1,
            SW_SHOWMAXIMIZED = 3
        }


        IntPtr iPtr;

        public Form2()
        {
            InitializeComponent();
            m_wrapper = new UnmanagedWrapper();

            int val = m_wrapper.callTest();
            val = m_wrapper.callTest(11234);

            iPtr = new IntPtr(m_wrapper.SDL_GetWindowID(this.Width, this.Height));

            this.Text = "Hello " + iPtr;

            SetWindowPos(iPtr, IntPtr.Zero, 0, 0, 0, 0, (SetWindowPosFlags.SWP_SHOWWINDOW | SetWindowPosFlags.SWP_NOSIZE));
            SetParent(iPtr, panel1.Handle);
            //ShowWindow(iPtr, ShowWindowCommand.SW_SHOWNORMAL);
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            Debug.WriteLine("Form closing!");
        }

        private void Form2_Resize(object sender, EventArgs e)
        {
            Debug.WriteLine("Resize Form");
            panel1.Size = this.Size;
            panel1.Location = new Point(0, 0);
            m_wrapper.resize(this.Size.Width, this.Size.Height);
            SetWindowPos(iPtr, IntPtr.Zero, 0, 0, this.Size.Width, this.Size.Height, (SetWindowPosFlags.SWP_SHOWWINDOW ));


        }
    }
}
