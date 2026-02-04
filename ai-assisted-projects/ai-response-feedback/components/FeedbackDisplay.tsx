import React from 'react';
import { type IFeedback, type IFeedbackCriterion } from '../types';

const getScoreColor = (score: number): string => {
  if (score >= 8) return 'text-green-400';
  if (score >= 5) return 'text-yellow-400';
  return 'text-red-400';
};

const CriterionCard: React.FC<{ item: IFeedbackCriterion }> = ({ item }) => (
  <div className="bg-slate-800/50 p-6 rounded-xl ring-1 ring-white/10 transition-transform duration-300 hover:scale-[1.02] hover:ring-cyan-400/50">
    <div className="flex justify-between items-center mb-3">
      <h3 className="text-lg font-semibold text-cyan-300">{item.criterion}</h3>
      <div className="flex items-center space-x-2">
        <span className={`text-2xl font-bold ${getScoreColor(item.score)}`}>{item.score}</span>
        <span className="text-slate-400 text-sm">/ 10</span>
      </div>
    </div>
    <p className="text-slate-300 leading-relaxed">{item.feedback}</p>
  </div>
);

const FeedbackDisplay: React.FC<{ feedback: IFeedback }> = ({ feedback }) => {
  return (
    <div className="space-y-8 animate-fade-in">
      <div className="bg-slate-800/50 rounded-2xl shadow-lg p-6 ring-1 ring-white/10">
        <h2 className="text-2xl font-bold mb-4 text-fuchsia-400">Overall Summary</h2>
        <p className="text-slate-300 leading-relaxed">{feedback.summary}</p>
      </div>

      <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
        {feedback.criteria.map((item) => (
          <CriterionCard key={item.criterion} item={item} />
        ))}
      </div>
      
      <div className="bg-slate-800/50 rounded-2xl shadow-lg p-6 ring-1 ring-white/10">
        <h2 className="text-2xl font-bold mb-4 text-fuchsia-400">Suggestions for Improvement</h2>
        <p className="text-slate-300 leading-relaxed whitespace-pre-line">{feedback.suggestions}</p>
      </div>

      <div className="bg-slate-800/50 rounded-2xl shadow-lg p-6 ring-1 ring-white/10">
        <h2 className="text-2xl font-bold mb-4 text-fuchsia-400">Suggested Revision</h2>
        <p className="text-slate-300 leading-relaxed whitespace-pre-line">{feedback.revisedResponse}</p>
      </div>
    </div>
  );
};

export default FeedbackDisplay;
