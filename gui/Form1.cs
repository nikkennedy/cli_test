using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace gui
{
    public partial class Form1 : Form
    {

        [DllImport("user32.dll", SetLastError = true)]
        static extern bool SetWindowPos(IntPtr handle, IntPtr handleAfter, int x, int y, int cx, int cy, SetWindowPosFlags flags);
        [DllImport("user32.dll", SetLastError = true)]
        static extern IntPtr SetParent(IntPtr child, IntPtr newParent);
        [DllImport("user32.dll", SetLastError = true)]
        static extern bool ShowWindow(IntPtr handle, ShowWindowCommand command);     

        enum SetWindowPosFlags : uint
        {
            SWP_SHOWWINDOW = 0x0400,
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
        
        UnmanagedWrapper m_wrapper = new UnmanagedWrapper();

        public Form1()
        {
            InitializeComponent();

            int val = m_wrapper.callTest();
            val = m_wrapper.callTest(11234);

            IntPtr iPtr = new IntPtr(m_wrapper.SDL_GetWindowID());

            this.Text = "Hello " + iPtr;

            SetWindowPos(iPtr, this.Handle, 0, 0, 0, 0, (SetWindowPosFlags.SWP_SHOWWINDOW | SetWindowPosFlags.SWP_NOSIZE));
            SetParent(iPtr, this.Handle);
            ShowWindow(iPtr, ShowWindowCommand.SW_SHOWNORMAL);

        }
    }
}
