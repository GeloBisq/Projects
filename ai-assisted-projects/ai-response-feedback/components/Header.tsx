
import React from 'react';

const Header: React.FC = () => {
  return (
    <header className="bg-slate-900/60 backdrop-blur-md sticky top-0 z-10 border-b border-slate-700/50">
      <div className="max-w-4xl mx-auto p-4 flex items-center justify-center">
         <div className="flex items-center space-x-3">
          <svg
            xmlns="http://www.w3.org/2000/svg"
            viewBox="0 0 24 24"
            fill="currentColor"
            className="w-8 h-8 text-cyan-400"
          >
            <path d="M12 2c5.523 0 10 4.477 10 10s-4.477 10-10 10S2 17.523 2 12 6.477 2 12 2Zm-2.002 9.416a1.53 1.53 0 0 0 .53 1.442l.002.002.002.002a1.53 1.53 0 0 0 2.12-.083l4.242-4.242a.75.75 0 1 1 1.06 1.06l-4.242 4.242a3.03 3.03 0 0 1-4.242.165l-.002-.002-.002-.001a3.03 3.03 0 0 1-.586-4.155.75.75 0 1 1 1.135.972Z" />
            <path d="M12.002 11.23a1.53 1.53 0 0 0-1.01.416l-2.48 2.48a.75.75 0 1 0 1.06 1.06l2.48-2.48a.03.03 0 0 1 .043-.033.75.75 0 0 0 .967-1.144.03.03 0 0 1-.03-.042A1.53 1.53 0 0 0 12 11.23Z" />
          </svg>
          <h1 className="text-2xl font-bold tracking-tight bg-gradient-to-r from-cyan-400 to-fuchsia-500 text-transparent bg-clip-text">
            AI Response Feedback
          </h1>
        </div>
      </div>
    </header>
  );
};

export default Header;
