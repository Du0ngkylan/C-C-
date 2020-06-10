// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//
/// @file   LoggerUtils.cs
/// @brief
/// @date    
// 
//
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

using MetroLog;
using MetroLog.Targets;
using System;
using System.Runtime.CompilerServices;

namespace Utils
{
    /// <summary>
    /// Log utility class
    /// </summary>
    internal class LoggerUtils
    {
        private ILogger log = null;

        /// <summary>
        /// constructor
        /// </summary>
        /// <param name="clazz">name of the class</param>
        public LoggerUtils(string clazz)
        {
            LogManagerDefault.GetInstance();
#if DEBUG
            // Always log during debug build.
            log = LogManagerFactory.DefaultLogManager.GetLogger(clazz);
#else
            // Only log if there is a MetroLogs folder during release build
            string logPath = Windows.Storage.ApplicationData.Current.LocalFolder.Path + @"\MetroLogs";
            if (System.IO.Directory.Exists(logPath))
            {
                log = LogManagerFactory.DefaultLogManager.GetLogger(clazz);
            }
#endif
        }

        /// <summary>
        /// Trace
        /// </summary>
        /// <param name="message"></param>
        /// <param name="ex"></param>
        public void Trace(string message, Exception ex = null,
           [CallerMemberName] string memberName = "",
           [CallerFilePath] string sourceFilePath = "",
           [CallerLineNumber] int sourceLineNumber = 0)
        {
            if (log != null)
            {
                log.Trace(Message(message, memberName, sourceLineNumber), ex);
            }
        }

        /// <summary>
        /// Debug
        /// </summary>
        /// <param name="message"></param>
        /// <param name="ex"></param>
        public void Debug(string message, Exception ex = null,
            [CallerMemberName] string memberName = "",
            [CallerFilePath] string sourceFilePath = "",
            [CallerLineNumber] int sourceLineNumber = 0)
        {
            if (log != null)
            {
                log.Debug(Message(message, memberName, sourceLineNumber), ex);
            }
        }

        /// <summary>
        /// Info
        /// </summary>
        /// <param name="message"></param>
        /// <param name="ex"></param>
        public void Info(string message, Exception ex = null,
           [CallerMemberName] string memberName = "",
           [CallerFilePath] string sourceFilePath = "",
           [CallerLineNumber] int sourceLineNumber = 0)
        {
            if (log != null)
            {
                log.Info(Message(message, memberName, sourceLineNumber), ex);
            }
        }

        /// <summary>
        /// Warn
        /// </summary>
        /// <param name="message"></param>
        /// <param name="ex"></param>
        public void Warn(string message, Exception ex = null,
            [CallerMemberName] string memberName = "",
            [CallerFilePath] string sourceFilePath = "",
            [CallerLineNumber] int sourceLineNumber = 0)
        {
            if (log != null)
            {
                log.Warn(Message(message, memberName, sourceLineNumber), ex);
            }
        }

        /// <summary>
        /// Error
        /// </summary>
        /// <param name="message"></param>
        /// <param name="ex"></param>
        public void Error(string message, Exception ex = null,
             [CallerMemberName] string memberName = "",
             [CallerFilePath] string sourceFilePath = "",
             [CallerLineNumber] int sourceLineNumber = 0)
        {
            if (log != null)
            {
                log.Error(Message(message, memberName, sourceLineNumber), ex);
            }
        }

        /// <summary>
        /// Fatal
        /// </summary>
        /// <param name="message"></param>
        /// <param name="ex"></param>
        public void Fatal(string message, Exception ex = null,
             [CallerMemberName] string memberName = "",
             [CallerFilePath] string sourceFilePath = "",
             [CallerLineNumber] int sourceLineNumber = 0)
        {
            if (log != null)
            {
                log.Fatal(Message(message, memberName, sourceLineNumber), ex);
            }
        }

        /// <summary>
        /// Sequence
        /// </summary>
        /// <param name="message"></param>
        /// <param name="ex"></param>
        public void Sequence(string message, Exception ex = null,
             [CallerMemberName] string memberName = "",
             [CallerFilePath] string sourceFilePath = "",
             [CallerLineNumber] int sourceLineNumber = 0)
        {
            if (log != null)
            {
                log.Info(Message("SequenceLog : " + message, memberName, sourceLineNumber), ex);
            }
        }

        /// <summary>
        /// Message for log
        /// </summary>
        /// <param name="message">message</param>
        /// <param name="memberName">the method</param>
        /// <param name="sourceLineNumber">line number</param>
        /// <returns></returns>
        private string Message(string message, string memberName, int sourceLineNumber)
        {
            return string.Format("{0}:LINE{1}:{2}", memberName, sourceLineNumber, message);
        }
    }
    
    /// <summary>
    /// LogManagerFactory.DefaultConfiguration
    /// Implement with singleton so that it can be set only once.
    /// </summary>
    class LogManagerDefault
    {
        private static LogManagerDefault instance;

        internal static LogManagerDefault GetInstance()
        {
            if (instance == null)
            {
                instance = new LogManagerDefault();
            }
            return instance;
        }

        private LogManagerDefault()
        {
            LogManagerFactory.DefaultConfiguration.AddTarget(LogLevel.Trace, LogLevel.Fatal, new StreamingFileTarget(new CustomLayout()));
        }
    }

    class CustomLayout : MetroLog.Layouts.Layout
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="context"></param>
        /// <param name="info"></param>
        /// <returns></returns>
        public override string GetFormattedString(LogWriteContext context, LogEventInfo info)
        {
            // Change time zone.
            DateTime dateTime = info.TimeStamp.LocalDateTime;
            string time = dateTime.ToString("yyyy-MM-dd HH:mm:ss.fff");

            string s = $"{info.SequenceID}|{time}|{info.Level}|{info.Logger}|{info.Message}";
            if (info.Exception != null)
            {
                // Match the notation with the default.
                s += $" --> {info.Exception}";
            }
            return s;
        }
    }
}
