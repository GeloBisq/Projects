import { GoogleGenAI, Type } from "@google/genai";
import { type IFeedback } from '../types';

if (!process.env.API_KEY) {
  throw new Error("API_KEY environment variable is not set.");
}

const ai = new GoogleGenAI({ apiKey: process.env.API_KEY });

const responseSchema = {
  type: Type.OBJECT,
  properties: {
    criteria: {
      type: Type.ARRAY,
      description: "An array of feedback objects for different criteria.",
      items: {
        type: Type.OBJECT,
        properties: {
          criterion: { type: Type.STRING, description: "The name of the evaluation criterion (e.g., Creativity, Relevance)." },
          score: { type: Type.INTEGER, description: "A score from 1 to 10 for this criterion." },
          feedback: { type: Type.STRING, description: "Detailed feedback for this criterion." }
        },
        required: ["criterion", "score", "feedback"]
      }
    },
    summary: {
      type: Type.STRING,
      description: "An overall summary of the feedback."
    },
    suggestions: {
      type: Type.STRING,
      description: "Specific suggestions for improvement."
    },
    revisedResponse: {
      type: Type.STRING,
      description: "A revised version of the user's response, incorporating the suggestions for improvement."
    }
  },
  required: ["criteria", "summary", "suggestions", "revisedResponse"]
};

export const getFeedback = async (prompt: string, userResponse: string): Promise<IFeedback> => {
  const geminiPrompt = `
    You are an expert evaluator providing constructive feedback on written responses.
    Analyze the following user response based on the provided prompt.

    **Prompt:**
    "${prompt}"

    **User's Response:**
    "${userResponse}"

    Evaluate the response based on the following criteria:
    1.  **Relevance:** How directly and completely does the response answer the prompt?
    2.  **Creativity:** Does the response show originality, imagination, or a unique perspective?
    3.  **Clarity & Cohesion:** Is the response well-structured, easy to read, and are the ideas connected logically?
    4.  **Depth of Thought:** Does the response demonstrate a deep understanding of the topic or is it superficial?

    For each criterion, provide a score from 1 (poor) to 10 (excellent) and detailed, constructive feedback.
    Then, provide an overall summary of the response's strengths and weaknesses, and offer specific, actionable suggestions for improvement.
    Finally, provide a revised version of the user's response that incorporates your suggestions and improves upon the original.

    Return your entire analysis in the specified JSON format. Do not include any text outside of the JSON object.
  `;

  try {
    const response = await ai.models.generateContent({
      model: "gemini-2.5-flash",
      contents: geminiPrompt,
      config: {
        responseMimeType: "application/json",
        responseSchema: responseSchema,
      },
    });

    const jsonText = response.text.trim();
    const parsedFeedback: IFeedback = JSON.parse(jsonText);
    return parsedFeedback;
  } catch (error) {
    console.error("Error fetching or parsing feedback from Gemini:", error);
    throw new Error("Failed to get feedback from the AI. Please check the console for more details.");
  }
};
