import { GithubItem, Nullable } from "../types";
import { ReactNode, useState } from "react";
import { Affix, Card, Col, Row, Typography } from "antd";
import ListItem from "./ListItem";

interface Props<T> {
    title: string;
    items: T[];
    getItemDescription: (item: T) => string;
    detailLayout: (item: Nullable<T>) => Nullable<ReactNode>;
}

const MasterDetail = <T extends GithubItem>({
    title,
    items,
    getItemDescription,
    detailLayout,
}: Props<T>) => {
    const [selectedItem, setSelectedItem] = useState<Nullable<T>>(null);

    return (
        <>
            <Row justify="center">
                <Col><Typography.Title level={3}>{title}</Typography.Title></Col>
            </Row>
            <Row>
                <Col span={6}>
                    <Affix offsetTop={20}>
                        <div
                            id="scrollableDiv"
                            style={{
                                height: "80vh",
                                overflow: "auto",
                                padding: "0 5px",
                            }}
                        >
                            <Card bordered={false} style={{ boxShadow: "none" }}>
                                {items.map((item, index) => (
                                    <ListItem
                                        key={index}
                                        item={item}
                                        onSelect={setSelectedItem}
                                        selectedItem={selectedItem}
                                        title={getItemDescription(item)}
                                    />
                                ))}
                            </Card>
                        </div>
                    </Affix>
                </Col>
                {detailLayout(selectedItem)}
            </Row>
        </>
    );
};

export default MasterDetail;

