using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMandelbrot
{
    public class ProgressEventArgs : EventArgs
    {
        private double _progress;

        public ProgressEventArgs(double p)
        {
            Progress = p;
        }
        public double Progress { get => _progress; set => _progress = value; }

    }
}
