import { Carousel, Col, Row, Spin, Typography } from "antd";
import React, { useEffect, useState } from "react";
import "prismjs/themes/prism-okaidia.min.css";
import Prism from "prismjs";
import { CodeSnippet, Gist } from "../../types";
import { invoke } from "@tauri-apps/api/tauri";

interface Props {
    gist: Gist;
}

const GistDetails: React.FC<Props> = ({ gist }) => {
    const [snippets, setSnippets] = useState<CodeSnippet[]>([]);
    const [isLoading, setIsLoading] = useState(true);

    useEffect(() => {
        Prism.highlightAll();
    }, [snippets]);

    useEffect(() => {
        const getSnippets = async () => {
            setIsLoading(true);
            const snippets: CodeSnippet[] = await Promise.all(
                Object.values(gist.files).map(async (file) => ({
                    language: file.language?.toLowerCase() || "text",
                    content: await invoke("get_gist_content", { url: file.raw_url }),
                }))
            );
            setSnippets(snippets);
            setIsLoading(false);
        };
        getSnippets();
    }, [gist]);

    return (
        <Spin tip="Loading" spinning={isLoading}>
            <Row justify="center">
                <Col>
                    {gist.description && (
                        <Typography.Text strong>{gist.description}</Typography.Text>
                    )}
                </Col>
            </Row>
            <div>
                <Carousel
                    autoplay
                    style={{ backgroundColor: "#272822", height: "100%" }}
                >
                    {snippets.map((snippet, index) => (
                        <pre key={index}>
                            <code className={`language-${snippet.language}`}>
                                {snippet.content}
                            </code>
                        </pre>
                    ))}
                </Carousel>
            </div>
        </Spin>
    );
};

export default GistDetails;
