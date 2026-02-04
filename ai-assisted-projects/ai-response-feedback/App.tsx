
import React, { useState, useCallback } from 'react';
import { getFeedback } from './services/geminiService';
import { type IFeedback } from './types';
import Header from './components/Header';
import InputField from './components/InputField';
import FeedbackDisplay from './components/FeedbackDisplay';
import Spinner from './components/Spinner';

const App: React.FC = () => {
  const [prompt, setPrompt] = useState<string>('');
  const [userResponse, setUserResponse] = useState<string>('');
  const [feedback, setFeedback] = useState<IFeedback | null>(null);
  const [isLoading, setIsLoading] = useState<boolean>(false);
  const [error, setError] = useState<string | null>(null);

  const handleGetFeedback = useCallback(async () => {
    if (!prompt.trim() || !userResponse.trim()) {
      setError('Please provide both a prompt and a response.');
      return;
    }

    setIsLoading(true);
    setError(null);
    setFeedback(null);

    try {
      const result = await getFeedback(prompt, userResponse);
      setFeedback(result);
    } catch (err) {
      setError(err instanceof Error ? err.message : 'An unknown error occurred.');
      console.error(err);
    } finally {
      setIsLoading(false);
    }
  }, [prompt, userResponse]);

  return (
    <div className="min-h-screen bg-slate-900 text-slate-200 font-sans">
      <Header />
      <main className="max-w-4xl mx-auto p-4 md:p-8">
        <div className="bg-slate-800/50 rounded-2xl shadow-2xl p-6 md:p-8 ring-1 ring-white/10 backdrop-blur-sm">
          <div className="grid grid-cols-1 gap-6">
            <h2 className="text-xl font-semibold text-cyan-400">Your Task</h2>
            <InputField
              id="prompt"
              label="The Prompt or Question"
              value={prompt}
              onChange={(e) => setPrompt(e.target.value)}
              placeholder="e.g., Describe the color blue to someone who has never seen it."
              rows={3}
            />
            <h2 className="text-xl font-semibold text-cyan-400">Your Answer</h2>
            <InputField
              id="userResponse"
              label="Your Response"
              value={userResponse}
              onChange={(e) => setUserResponse(e.target.value)}
              placeholder="e.g., Blue is the feeling of a cool breeze on a hot day..."
              rows={8}
            />
          </div>
          <div className="mt-8 text-center">
            <button
              onClick={handleGetFeedback}
              disabled={isLoading || !prompt.trim() || !userResponse.trim()}
              className="w-full md:w-auto bg-cyan-500 hover:bg-cyan-400 disabled:bg-slate-600 disabled:cursor-not-allowed text-slate-900 font-bold py-3 px-10 rounded-full transition-all duration-300 ease-in-out transform hover:scale-105 shadow-lg shadow-cyan-500/20 disabled:shadow-none"
            >
              {isLoading ? (
                <div className="flex items-center justify-center">
                  <Spinner />
                  <span className="ml-2">Analyzing...</span>
                </div>
              ) : (
                'Get Feedback'
              )}
            </button>
          </div>
        </div>

        {error && (
          <div className="mt-8 bg-red-500/20 text-red-300 p-4 rounded-lg text-center ring-1 ring-red-500/50">
            <strong>Error:</strong> {error}
          </div>
        )}
        
        {feedback && !isLoading && (
          <div className="mt-8">
            <FeedbackDisplay feedback={feedback} />
          </div>
        )}

      </main>
    </div>
  );
};

export default App;
