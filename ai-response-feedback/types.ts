export interface IFeedbackCriterion {
  criterion: string;
  score: number;
  feedback: string;
}

export interface IFeedback {
  criteria: IFeedbackCriterion[];
  summary: string;
  suggestions: string;
  revisedResponse: string;
}
