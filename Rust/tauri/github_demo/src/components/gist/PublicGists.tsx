import { useEffect, useState } from "react";
import GistDetails from "./GistDetails";
import MasterDetail from "../MasterDetail";
import { Col, message } from "antd";
import { Gist, Nullable } from "../../types";
import { invoke } from "@tauri-apps/api/tauri";
import { getErrorMessage } from "../../helper";

const PublicGists = () => {
    const [gists, setGists] = useState<Gist[]>([]);
    const [messageApi, contextHolder] = message.useMessage();

    useEffect(() => {
        const getGists = async () => {
            try {
                const gists: Gist[] = await invoke("get_public_gists");
                setGists(gists);
            } catch (error) {
                messageApi.open({
                    type: "error",
                    content: getErrorMessage(error),
                });
            }
        };
        getGists();
    }, []);

    const title = "Public Gists";
    const getItemDescription = (gist: Gist) => gist.description || "No description provided";
    const detailLayout = (gist: Nullable<Gist>) => {
        if (!gist) return null;
        return (
            <Col span={18}>
                <GistDetails gist={gist} />
            </Col>
        );
    };

    return (
        <>
            {contextHolder}
            <MasterDetail
                title={title}
                items={gists}
                getItemDescription={getItemDescription}
                detailLayout={detailLayout}
            />
        </>
    );
};

export default PublicGists;
