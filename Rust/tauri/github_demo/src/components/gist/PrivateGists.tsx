import { useEffect, useState } from "react";
import { useAuthContext } from "../context/AuthContext";
import GistDetails from "./GistDetails";
import MasterDetail from "../MasterDetail";
import { Col, message } from "antd";
import { Gist, Nullable } from "../../types";
import { invoke } from "@tauri-apps/api/tauri";
import { getErrorMessage } from "../../helper";

const PrivateGists = () => {
    const [gists, setGists] = useState<Gist[]>([]);
    const { token } = useAuthContext();
    const [messageApi, contextHolder] = message.useMessage();

    useEffect(() => {
        const getGists = async () => {
            if (token) {
                try {
                    const gists: Gist[] = await invoke(
                        "get_gists_for_authenticated_user",
                        { token }
                    );
                    setGists(gists);
                } catch (error) {
                    messageApi.open({
                        type: "error",
                        content: getErrorMessage(error),
                    });
                }
            }
        };
        getGists();
    }, [token]);

    const title = "Private Gists";
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

export default PrivateGists;
